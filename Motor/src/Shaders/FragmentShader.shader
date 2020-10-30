#ifndef FRAGMENTSHADER_H
#define FRAGMNETSHADER_H

namespace Graficos1 {

	//Fragment Shader
	static const char* fShader = "						\n\
#version 330										\n\
in vec4 vColor;										\n\										\n\
out vec4 colour;									\n\
void main(){										\n\
	colour = vColor;								\n\
}";

}

#endif