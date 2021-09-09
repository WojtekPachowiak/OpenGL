#include "Input.h"
#include <bitset>
#include "GLFW/glfw3.h"

//scroll
double _xoffset, _yoffset;
//mouse
double _xpos, _ypos;
//keyboard
int _key, _action;


//input
std::uint_fast8_t inputs{};
constexpr std::uint_fast8_t key_a{ 1 << 0 }; // 0000 0001
constexpr std::uint_fast8_t key_s{ 1 << 1 }; // 0000 0010
constexpr std::uint_fast8_t key_d{ 1 << 2 }; // 0000 0100
constexpr std::uint_fast8_t key_w{ 1 << 3 }; // 0000 1000
constexpr std::uint_fast8_t key_lshift{ 1 << 4 }; // 0001 0000


void Input::ProcessInput()
{
    if (_action == GLFW_PRESS) {
        if (_key == GLFW_KEY_LEFT_SHIFT) inputs |= key_lshift;
        if (_key == GLFW_KEY_W) inputs |= key_w;
        if (_key == GLFW_KEY_S) inputs |= key_s;
        if (_key == GLFW_KEY_A) inputs |= key_a;
        if (_key == GLFW_KEY_D) inputs |= key_d;
    }
    inputs &= 0;

    

    camera.ProcessKeyboardAndMove(inputs, Time::deltaTime);

    inputs &= 0;
}



void Input::SetKeyboard(int key, int action)
{
    _key = key;
    _action = action;
}


void Input::SetScroll(double xoffset, double yoffset)
{
    _xoffset = xoffset;
    _yoffset = yoffset;
}


void Input::SetMouse(double xpos, double ypos)
{
    _xpos = xpos;
    _ypos = ypos;
}