#include "glew.h"
#include "GL/glew.h"
#include <iostream>

bool GLEW::Init()
{
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW!" << std::endl;
        return false;
    }
    
}