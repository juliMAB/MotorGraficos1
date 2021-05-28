#include "Shader.h"
#include "glew.h"
#include <iostream>

namespace Coco {

	Shader::Shader() {
		shaderID = 0;
	}

	Shader::~Shader() {

	}
	void Shader::CompileShader(const char* vertexCode, const char* fragmentCode) {
		shaderID = glCreateProgram();
		if (!shaderID) {
			std::cout << "Error creating the shader program!" << std::endl;
			return;
		}

		AddShader(shaderID, vertexCode, GL_VERTEX_SHADER);
		AddShader(shaderID, fragmentCode, GL_FRAGMENT_SHADER);

		int result = 0;
		char eLog[1024] = { 0 };

		glLinkProgram(shaderID);

		glGetProgramiv(shaderID, GL_LINK_STATUS, &result);

		if (!result) {
			glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
			std::cout << "Error linking program: " << eLog << std::endl;
			return;
		}

		glValidateProgram(shaderID);
		glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &result);
		if (!result) {
			glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
			std::cout << "Error validating program: " << eLog << std::endl;
			return;
		}

	}

	void Shader::AddShader(uint program, const char* shaderCode, uint type) {
		uint theShader = glCreateShader(type);

		const char* code[1];
		code[0] = shaderCode;

		int codeLength[1];
		codeLength[0] = strlen(shaderCode);

		glShaderSource(theShader, 1, code, codeLength);

		glCompileShader(theShader);

		int result = 0;
		char eLog[1024] = { 0 };

		glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);

		if (!result) {
			glGetProgramInfoLog(theShader, sizeof(eLog), NULL, eLog);
			std::cout << "Error compiling the " << type << " program: " << eLog << std::endl;
			return;
		}
		glAttachShader(program, theShader);
	}

	std::string Shader::ReadFile(const char* location) {
		std::string content;
		std::ifstream fileStream(location, std::ios::in);

		if (!fileStream.is_open()) {
			std::cout << "Failed to read the file: " << location << std::endl;
			return "";
		}

		std::string line = "";
		while (!fileStream.eof()) {
			std::getline(fileStream, line);
			content.append(line + "\n");
		}

		fileStream.close();
		return content;
	}

	void Shader::CreateFromLocation(const char* vertexLocation, const char* fragmentLocation) {
		std::string vertexString = ReadFile(vertexLocation);
		std::string fragmentString = ReadFile(fragmentLocation);

		const char* vertexCode = vertexString.c_str();
		const char* fragmentCode = fragmentString.c_str();

		CompileShader(vertexCode, fragmentCode);
	}

	void Shader::ClearShader() {
		if (shaderID != 0) {
			glDeleteProgram(shaderID);
			shaderID = 0;
		}
	}
	uint Shader::GetShader() {
		return shaderID;
	}
}