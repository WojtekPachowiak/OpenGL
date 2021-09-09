//imgui
#include"imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

//GLEW and GLFW
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//glm
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

//shader loading
#include "shader_s.h"


//standard libraries
#include <iostream>

//time
#include "time_m.h"



//declarations and constants
#include "declarations.h"

//camera
#include "camera.h"
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

//model importing
#include "model.h"

//ImGUI controller
#include "imgui_controller.h"

#include "window.h"


//TODO:
//1. drawCube function
//2. choose viewport navigation mode
//3. encapsulate ImGui settings in ImGui_controller
//4. entering relative path 
//5. Input class
//6. GLFW class
//7. GLEW class
//8. Save state (write to file)



int main()
{
    int status = Window::Init();
    GLFWwindow* window = nullptr;
    window = Initialize_GLFW_GLEW(window);
    if (window == nullptr) return -1;
       
    //setup imgui controller
    ImGui_controller::Setup(Window::GetInstance());

    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(true);

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader program
   /* const char* fragPath = GetPath(shadersPath, "modelLoading.frag");
    const char* vertPath = GetPath(shadersPath, "modelLoading.vert");
    Shader ourShader(fragPath, vertPath);*/
    Shader ourShader("C:/OpenGL/OpenGL/OpenGL/res/shaders/modelLoading.vert", R"(C:\OpenGL\OpenGL\OpenGL\res\shaders\modelLoading.frag)");
    Shader default_unlit("C:/OpenGL/OpenGL/OpenGL/res/shaders/default_unlit.vert", R"(C:\OpenGL\OpenGL\OpenGL\res\shaders\default_unlit.frag)");

    // load models
    //Model ourModel(GetPath(modelsPath,"backpack/backpack.obj"));
    Model ourModel("C:/OpenGL/OpenGL/OpenGL/res/models/default_shapes/cube.obj");
    Model pointLightCube("C:/OpenGL/OpenGL/OpenGL/res/models/default_shapes/cube.obj");
    // draw in wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //lights
    PointLight pointLight;
    SpotLight spotLight;
    Material mat;


    // render loop
    while (!glfwWindowShouldClose(window)) // -------------------------------------------------------------------------------//
    {
        ImGui_controller::NewFrame();
        Time::DeltaTime();
        
        // input
        processInput(window);

        // render
        glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        //view, projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();



        //render model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        ourShader.use();
        ourShader.setMat4("model", model);
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
        ourModel.Draw(ourShader);



        //ImGui
        {
        ImGui::Begin("##default");
        //ImGui::Text("Camera settings");
        const char* items[]{ "Fly","Mouse drag" };
        int selectedItem;
        ImGui::Combo("Camera settings", &selectedItem, items, 2);
        //ImGui::Text("Material settings");
        //ImGui::SliderFloat("shininess", &mat.shininess, 0.0f, 256.0f);
        ImGui_controller::PointLightGUI(pointLight);

        

        //ImGui::Text("Flash light");
        //ImGui::ColorEdit3("ambient##spot", glm::value_ptr(spotLight.ambient));
        //ImGui::ColorEdit3("diffuse##spot", glm::value_ptr(spotLight.diffuse));
        //ImGui::ColorEdit3("specular##spot", glm::value_ptr(spotLight.specular));
        //ImGui::SliderFloat("size", &spotLight.cutOff, 0.0f,90.f);
        //ImGui::SliderFloat("sharpness", &spotLight.outerCutOff, 0.0f, 90.f);


        ImGui::End();
        }




        

        //render ImGui
        ImGui_controller::Render();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }  // -------------------------------------------------------------------------------//


    
    // glfw: terminate, clearing all previously allocated GLFW resources.
    ImGui_controller::Shutdown();
    glfwTerminate();
    return 0;
}




