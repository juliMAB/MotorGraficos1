#ifndef FRAGMENTSHADER_H
#define FRAGMNETSHADER_H

namespace Graficos1 {

	//Fragment Shader
	static const char* fShader = "					\n\
#version 330										\n\
out vec4 Fragcolor;									\n\
in vec4 vertexColor;								\n\
void main() {										\n\
	FragColor = vertexColor;						\n\
}";												
}

#endif