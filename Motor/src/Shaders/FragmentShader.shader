#ifndef FRAGMENTSHADER_H
#define FRAGMNETSHADER_H

namespace Graficos1 {

	//Fragment Shader
	static const char* fShader = "					\n\
#version 330										\n\
in vec4 vColor;										\n\
out vec4 colour;									\n\
in vec2 TexCoord;									\n\
uniform sampler2D theTexture;						\n\
uniform bool useTexture;							\n\
uniform bool useLight;								\n\
struct DirectionalLight {							\n\
		vec3 colour;								\n\
		float ambientIntensity;						\n\
};													\n\
uniform DirectionalLight directionalLight;			\n\
void main(){										\n\
	vec4 ambientColour = vec4(directionalLight.colour, 1.0f) * directionalLight.ambientIntensity;		\n\
	if(useTexture == false && useLight == true)		\n\
		colour = vColor * ambientColour;			\n\
	else if(useTexture == false && useLight == false)	\n\
		colour = vColor;							\n\
	else											\n\
		colour = texture(theTexture, TexCoord);		\n\
}";

}

#endif