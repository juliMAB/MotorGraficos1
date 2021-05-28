#ifndef SHADER_H
#define SHADER_H

#include "../Exports/Exports.h"

#include <fstream>
#include <string>

namespace Coco {
	typedef unsigned int uint;
	class GraficosEngine_API Shader {

	private:
		uint shaderID;
		
		void CompileShader(const char* vertexCode, const char* fragmentCode);
		void AddShader(uint program, const char* shaderCode, uint type);
		std::string ReadFile(const char* location);
	public:
		Shader();
		~Shader();
		void CreateFromLocation(const char* vertexLocation, const char* fragmentLocation);
		void ClearShader();
		uint GetShader();
	};

}

#endif