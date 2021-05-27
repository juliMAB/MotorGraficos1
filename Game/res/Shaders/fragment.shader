#version 330

int baseLightValue = 0;
int directionalLightValue = 1;
int pointLightValue = 2;
int flashLightValue = 3;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
out vec4 colour;
uniform sampler2D theTexture;
uniform bool useTexture;
uniform bool useLight;

struct BaseLight {
	vec3 colour;
};

struct DirectionalLight {
	vec3 colour;
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
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
};

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

uniform BaseLight baseLight;
uniform DirectionalLight directionalLight;
uniform PointLight pointLight;
uniform int typeOfLight;
uniform Material material;
uniform vec3 eyePosition;

vec3 CalcDirLight();
vec3 CalcPointLight();

void main() {
	if (useTexture == false && useLight == true) {
		vec3 result = vec3(1.0f, 1.0f, 1.0f);
		if (typeOfLight == baseLightValue)
			result = material.ambient * baseLight.colour;
		else if (typeOfLight == directionalLightValue)
			result = CalcDirLight();
		else if (typeOfLight == pointLightValue)
			result = CalcPointLight();
		colour = vec4(result, 1.0f);
	}
	else if (useTexture == false && useLight == false)
		colour = vec4(material.ambient, 1.0f);
	else
		colour = texture(theTexture, TexCoord);
}

vec3 CalcDirLight() {
	vec3 ambient = directionalLight.ambient * material.ambient;
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(-directionalLight.direction);

	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = directionalLight.diffuse * (diff * material.diffuse);
	vec3 viewDir = normalize(eyePosition - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = directionalLight.specular * (spec * material.specular);
	vec3 result = (ambient + diffuse + specular) * directionalLight.colour;
	return result;
}

vec3 CalcPointLight() {
	vec3 lightDir = pointLight.position - FragPos;
	float distance = length(lightDir);
	lightDir = normalize(lightDir);

	vec3 ambient = pointLight.ambient * material.ambient;
	vec3 norm = normalize(Normal);

	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = pointLight.diffuse * (diff * material.diffuse);
	vec3 viewDir = normalize(eyePosition - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = pointLight.specular * (spec * material.specular);

	float attenuation = pointLight.quadratic * distance * distance + pointLight.linear * distance + pointLight.constant;

	vec3 result = (ambient + diffuse + specular) * attenuation;
	return result * pointLight.colour;
}
