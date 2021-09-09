#pragma once
#include"glm/glm.hpp"


namespace g {

//const char* GetPath(const char* directory, std::string fileName);
//constants
constexpr float PI = 3.14159274101257324219f;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;
glm::vec3 backgroundColor = glm::vec3(0.1f, 0.07f, 0.05f);


//time
float Time::deltaTime = 0.0;
float Time::lastFrame = 0.0;



// camera
float lastX = (float)SCR_WIDTH / 2.0;
float lastY = (float)SCR_HEIGHT / 2.0;
bool firstMouse = true;

//texture paths
const char* imagesPath = "res/images/";

//model paths
const char* modelsPath = "res/models/";

//shader paths
const char* shadersPath = "res/shaders/";



//material
struct Material {
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
};


struct PointLight {
    glm::vec3 position;

    /*float constant;
    float linear;
    float quadratic;*/
    float intensity;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};


struct DirLight {
    glm::vec3 direction;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};


struct SpotLight {
    glm::vec3 position;
    glm::vec3 direction;
    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};



}