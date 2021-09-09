#pragma once

#include"GLFW/glfw3.h"

class Window
{
public:
	static GLFWwindow* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Window();
	}

	//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	/*void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);*/
	void processInput(GLFWwindow* window);
	GLFWwindow* Init();

private:
	Window() {}
	static GLFWwindow* s_Instance;
};
