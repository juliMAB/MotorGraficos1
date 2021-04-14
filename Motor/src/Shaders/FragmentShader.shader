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
struct Light {										\n\
	vec3 colour;									\n\
	vec3 ambient;									\n\
	vec3 diffuse;									\n\
	vec3 specular;									\n\
	float intensity;								\n\
};													\n\
struct Material{									\n\
	vec3 ambient;									\n\
	vec3 diffuse;									\n\
	vec3 specular;									\n\
	float shininess;								\n\
};													\n\
uniform Light light;								\n\
uniform Material material;							\n\
uniform vec3 eyePosition;							\n\
uniform vec3 posLight;								\n\
void main(){										\n\
	vec3 ambient = light.ambient * material.ambient;		\n\
	vec3 norm = normalize(Normal);					 \n\
	vec3 lightDir = normalize(posLight - FragPos);	 \n\
	float diff = max(dot(norm, lightDir), 0.0f);	 \n\
	vec3 diffuse = light.diffuse * (diff * material.diffuse);    \n\
	vec3 viewDir = normalize(eyePosition - FragPos); \n\
	vec3 reflectDir = reflect(-lightDir,norm);		 \n\
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess); \n\
	vec3 specular = light.specular * (spec * material.specular); \n\
	vec3 result = ambient + diffuse + specular;	\n\
	if(useTexture == false && useLight == true)		\n\
		colour = vec4(result,1.0f);		\n\
	else if(useTexture == false && useLight == false)	\n\
		colour = vColor;							\n\
	else											\n\
		colour = texture(theTexture, TexCoord);		\n\
}";

}

#endif