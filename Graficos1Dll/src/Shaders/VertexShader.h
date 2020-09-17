#ifndef VERTEXSHADER_H
#define VERTEXSHADER_H

#include <glew.h>
#include <glfw3.h>

namespace Graficos1 {

	// Vertex Shader
	static const char* vShader = "						\n\
#version 330										\n\
layout(location = 0) in vec3 pos;					\n\
layout(location = 1) in vec3 colorrrr;				\n\
out vec4 vColor;									\n\
void main(){										\n\
	gl_Position = vec4(0.9f * pos, 1.0f);			\n\
	vColor = vec4(colorrrr, 1.0f);					\n\
}";

}

#endif