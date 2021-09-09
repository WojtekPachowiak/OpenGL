#include "Input.h"
#include <bitset>

//input
std::uint_fast8_t inputs{};
constexpr std::uint_fast8_t key_a{ 1 << 0 }; // 0000 0001
constexpr std::uint_fast8_t key_s{ 1 << 1 }; // 0000 0010
constexpr std::uint_fast8_t key_d{ 1 << 2 }; // 0000 0100
constexpr std::uint_fast8_t key_w{ 1 << 3 }; // 0000 1000
constexpr std::uint_fast8_t key_lshift{ 1 << 4 }; // 0001 0000


void Input::ProcessInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        inputs |= key_lshift;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        inputs |= key_w;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        inputs |= key_s;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        inputs |= key_a;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        inputs |= key_d;

    camera.ProcessKeyboardAndMove(inputs, Time::deltaTime);

    inputs &= 0;
}