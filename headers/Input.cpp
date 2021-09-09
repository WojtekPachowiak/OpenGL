#include "Input.h"
#include <bitset>
#include "GLFW/glfw3.h"
#include <map>


enum class Key {
    W, A, S, D,
    TAB,
    MOUSE1,
    LSHIFT
};

//scroll
double _xoffset, _yoffset;
//mouse
double _xpos, _ypos;
//keyboard
int _key, _action;


//input
std::uint_fast64_t inputs{0};
//std::map<Key, uint_fast64_t> keyboard;

//constexpr std::uint_fast8_t key_a{ 1 << 0 }; // 0000 0001
//constexpr std::uint_fast8_t key_s{ 1 << 1 }; // 0000 0010
//constexpr std::uint_fast8_t key_d{ 1 << 2 }; // 0000 0100
//constexpr std::uint_fast8_t key_w{ 1 << 3 }; // 0000 1000
//constexpr std::uint_fast8_t key_lshift{ 1 << 4 }; // 0001 0000
//constexpr std::uint_fast8_t key_tab{ 1 << 5 }; // 0001 0000
//constexpr std::uint_fast8_t key_tab{ 1 << 6 }; // 0001 0000
//constexpr std::uint_fast8_t key_mouse1{ 1 << 7 }; // 0001 0000



bool Input::IsPressed(Key key)
{
    return key & inputs;
}


void Input::ProcessInput()
{
    if (_action == GLFW_PRESS) {
        if (_key == GLFW_KEY_LEFT_SHIFT) inputs |= LSHIFT;
        if (_key == GLFW_KEY_W) inputs |= W;
        if (_key == GLFW_KEY_S) inputs |= S;
        if (_key == GLFW_KEY_A) inputs |= A;
        if (_key == GLFW_KEY_D) inputs |= D;
        if (_key == GLFW_KEY_TAB) inputs |= TAB;
        if (_key == GLFW_MOUSE_BUTTON_1) inputs |= MOUSE1;
    }

    /// <summary>
    /// //
    /// </summary>

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