#pragma once
#ifndef INPUT_H
#define INPUT_H
#include "GLFW/glfw3.h"


class Input {
private:
	Input() {}\

	GLFWwindow* window;

public:
	void ProcessInput();

};
#endif // !INPUT_H
