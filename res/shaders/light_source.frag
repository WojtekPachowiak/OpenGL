#version 330 core
out vec4 FragColor;

//in vec3 ourColor;
//in vec2 texCoord;
//uniform sampler2D texture1;
//uniform sampler2D texture2;
//uniform float time;
uniform vec3 lightColor;

void main(){
    FragColor = vec4(lightColor ,1.0);
}