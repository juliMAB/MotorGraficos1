#ifndef FRAGMENTSHADER_H
#define FRAGMNETSHADER_H

namespace Graficos1 {

	//Fragment Shader
	static const char* fShader = "					\n\
#version 330										\n\
in vec4 vColor;										\n\
in vec2 TexCoord;									\n\
in vec3 Normal;										\n\
in vec3 FragPos;									\n\
out vec4 colour;									\n\
uniform sampler2D theTexture;						\n\
uniform bool useTexture;							\n\
uniform bool useLight;								\n\
struct DirectionalLight {							\n\
		vec3 colour;								\n\
		float ambientIntensity;						\n\
		vec3 direction;								\n\
		float diffuseIntensity;						\n\
};													\n\
struct Material{									\n\
	float specularIntensity;						\n\
	float shininess;								\n\
};													\n\
uniform DirectionalLight directionalLight;			\n\
uniform Material material;							\n\
uniform vec3 eyePosition;							\n\
void main(){										\n\
	vec4 ambientColour = vec4(directionalLight.colour, 1.0f) * directionalLight.ambientIntensity;			  \n\
	float diffuseFactor = max(dot(normalize(Normal), normalize(directionalLight.direction)), 0.0f);			  \n\
	vec4 diffuseColour = vec4(directionalLight.colour, 1.0f) * directionalLight.diffuseIntensity * diffuseFactor;	  \n\
	vec4 specularColour = vec4(0, 0, 0, 0);															  \n\
	if (diffuseFactor > 0.0f) {																								   \n\
		vec3 fragToEye = normalize(eyePosition - FragPos);												  \n\
		vec3 reflectedVertex = normalize(reflect(-directionalLight.direction, normalize(Normal)));		   \n\
		float specularFactor = max(dot(fragToEye, reflectedVertex),0.0f);											   \n\
		if (specularFactor > 0.0f) {																	  \n\
			specularFactor = pow(specularFactor, material.shininess);									 \n\
			specularColour = vec4(directionalLight.colour * material.specularIntensity * specularFactor, 1.0f);		 \n\
		}																								   \n\
	}																									    \n\
	if(useTexture == false && useLight == true)		\n\
		colour = vColor * (ambientColour + diffuseColour + specularColour);			\n\
	else if(useTexture == false && useLight == false)	\n\
		colour = vColor;							\n\
	else											\n\
		colour = texture(theTexture, TexCoord);		\n\
}";

}

#endif