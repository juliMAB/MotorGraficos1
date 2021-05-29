#version 330

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
out vec4 colour;
uniform sampler2D theTexture;
uniform bool useTexture;
uniform bool useLight;

struct BaseLight {
	vec3 colour;
	bool assigned;
};

struct DirectionalLight {
	vec3 colour;
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	bool assigned;
};

struct PointLight {
	vec3 position;
	vec3 colour;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
	bool assigned;
};

struct SpotLight{
	PointLight pLight;
	vec3 direction;
	float cutOff;
};

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

#define MAX_LIGHTS 3

uniform BaseLight baseLight;
uniform DirectionalLight directionalLight[MAX_LIGHTS];
uniform PointLight pointLight[MAX_LIGHTS];
uniform SpotLight spotLight[MAX_LIGHTS];

uniform Material material;
uniform vec3 eyePosition;

vec3 CalcDirLight(DirectionalLight dl);
vec3 CalcPointLight(PointLight pl);
vec3 CalcSpotLight(SpotLight sl);

void main() {
	if (useLight == true) {
		vec3 result = vec3(0,0,0);
		if(baseLight.assigned)
			result = material.ambient * baseLight.colour;
		for(int i=0;i<MAX_LIGHTS;i++){
			if(directionalLight[i].assigned)
				result += CalcDirLight(directionalLight[i]);
			if(spotLight[i].pLight.assigned)
				result += CalcSpotLight(spotLight[i]);
			if(pointLight[i].assigned)
				result += CalcPointLight(pointLight[i]);
		}
		colour = vec4(result, 1.0f);
	}
	else if (useLight == false)
		colour = vec4(material.ambient, 1.0f);
}

vec3 CalcDirLight(DirectionalLight dl) {
	vec3 ambient = dl.ambient * material.ambient;
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(-dl.direction);

	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = dl.diffuse * (diff * material.diffuse);
	vec3 viewDir = normalize(eyePosition - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = dl.specular * (spec * material.specular);
	vec3 result = (ambient + diffuse + specular) * dl.colour;
	return result;
}

vec3 CalcPointLight(PointLight pl) {
	vec3 lightDir = pl.position - FragPos;
	float distance = length(lightDir);
	lightDir = normalize(lightDir);

	vec3 ambient = pl.ambient * material.ambient;
	vec3 norm = normalize(Normal);

	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = pl.diffuse * (diff * material.diffuse);
	vec3 viewDir = normalize(eyePosition - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = pl.specular * (spec * material.specular);

	float attenuation = pl.quadratic * distance * distance + pl.linear * distance + pl.constant;

	vec3 result = (ambient + diffuse + specular) / attenuation;
	return result * pl.colour;
}

vec3 CalcSpotLight(SpotLight sl){
 	vec3 lightDir = normalize(sl.pLight.position - FragPos);
	float factor = dot(lightDir, normalize(-sl.direction));
	
	vec3 res = CalcPointLight(sl.pLight);
	return res * (1.0f - (1.0f - factor)*(1.0f/(1.0f - sl.cutOff)));
}
