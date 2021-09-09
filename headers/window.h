#pragma once

#include"GLFW/glfw3.h"

class Window
{
public:
	static Window* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Window();
	}

	static

	void processInput(GLFWwindow* window);
	bool Init();
	inline GLFWwindow* GetWindow() { return m_window; }


private:
	Window() {}
	GLFWwindow* m_window;
	
	static Window* s_Instance;
};
