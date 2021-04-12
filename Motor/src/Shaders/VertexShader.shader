#ifndef VERTEXSHADER_H
#define VERTEXSHADER_H

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

namespace Graficos1 {

	// Vertex Shader
	static const char* vShader = "					\n\
#version 330										\n\
layout(location = 0) in vec3 pos;					\n\
layout(location = 1) in vec3 colorrrr;				\n\
layout(location = 2) in vec2 tex;					\n\
layout(location = 3) in vec3 norm;					\n\
uniform mat4 model;									\n\
uniform mat4 projection;							\n\
uniform mat4 view;									\n\
out vec4 vColor;									\n\
out vec2 TexCoord;									\n\
out vec3 Normal;									\n\
void main(){										\n\
	gl_Position = projection * view * model * vec4(pos, 1.0f);			\n\
	vColor = vec4(colorrrr, 1.0f);					\n\
	TexCoord = tex;									\n\
	Normal = mat3(transpose(inverse(model))) * norm;\n\
}";


}

#endif