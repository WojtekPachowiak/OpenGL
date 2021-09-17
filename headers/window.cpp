#include "window.h"
#include "globals.h"
#include "iostream"
#include "Input.h"


//enum class WindowMode {
//    GUI,
//    IMMERSED
//};

using WindowMode = Window::WindowMode;

GLFWwindow* window;
WindowMode windowMode;


void SwitchWindowMode() {
    windowMode = (int)windowMode ? WindowMode::IMMERSED : WindowMode::GUI;
}



//// ---------------------------CALLBACKS-------------------------------////


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
    if (key == GLFW_KEY_TAB && action == GLFW_PRESS) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        SwitchWindowMode();
    }
    Input::SetKeyboard(key, action);

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    Input::SetMouse(xpos, ypos);
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    Input::SetScroll(xoffset, yoffset);
}


//------------------------ PUBLIC

bool Window::Init() {

    // glfw: initialize and configure
   // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(g::SCR_WIDTH, g::SCR_HEIGHT, "OpenGL graphics engine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetKeyCallback(window, key_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //glfwSetCursorPosCallback(window, cursor_position_callback);
    // GLEW: load all OpenGL function pointers
    // ---------------------------------------

    return true;
}



bool Window::ShouldWindowsClose()
{
    return glfwWindowShouldClose(window);
}

WindowMode Window::GetWindowMode()
{
    return windowMode;
}

GLFWwindow* Window::GetWindow()
{
    return window;
}