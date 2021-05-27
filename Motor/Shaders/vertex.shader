#version 330		

layout(location = 0) in vec3 pos;				
layout(location = 1) in vec3 colorrrr;			
layout(location = 2) in vec2 tex;				
layout(location = 3) in vec3 norm;	

uniform mat4 model;								
uniform mat4 projection;						
uniform mat4 view;			

out vec4 vColor;								
out vec2 TexCoord;								
out vec3 Normal;								
out vec3 FragPos;		

void main(){									
	gl_Position = projection * view * model * vec4(pos, 1.0f);		
	vColor = vec4(colorrrr, 1.0f);					
	TexCoord = tex;									
	Normal = mat3(transpose(inverse(model))) * norm;
	FragPos = (model * vec4(pos, 1.0)).xyz;		
}