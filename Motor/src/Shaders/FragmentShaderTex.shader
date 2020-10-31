#ifndef FRAGMENTSHADERTEX_H
#define FRAGMNETSHADERTEX_H

namespace Graficos1 {

		static const char* fShaderTex = 	"			\n\
#version 330											\n\
in vec2 TexCoord;										\n\
out vec4 colour;										\n\
uniform sampler2D theTexture;							\n\
void main() {											\n\
	colour = texture(theTexture, TexCoord);				\n\
}";												    

}

#endif