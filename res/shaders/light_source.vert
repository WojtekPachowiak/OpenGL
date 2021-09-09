#version 330 core
layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aColor;
//layout (location = 1) in vec2 aTexCoord;

//out vec3 ourColor;
//out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//mat2 Rotate(float a) {
//	float s = sin(a);
//	float c = cos(a);
//	return mat2(c, -s, s, c);
//}

void main(){
//	aPos = vec3(sin(time)*0.5+aPos.x,cos(time)*0.5+aPos.y,aPos.z);
	gl_Position = projection * view * model * vec4(aPos, 1.0);
//	ourColor = aPos;
//	texCoord = aTexCoord;
}