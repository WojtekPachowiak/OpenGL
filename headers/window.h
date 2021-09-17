#pragma once

#include"GLFW/glfw3.h"

//class Window
//{
//public:
//	bool Init();
//	inline GLFWwindow* GetWindow() { return m_window; }
//
//	inline WindowMode GetWindowMode() { return mode; }
//
//	void SwitchWindowMode() {  mode = (int)mode? WindowMode::IMMERSED : WindowMode::GUI; }
//
//
//private:
//	WindowMode mode;
//
//	Window() {}
//	GLFWwindow* m_window;
//	
//	static Window* s_Instance;
//};



namespace Window {
	enum class WindowMode {
		GUI,
		IMMERSED
	};

	bool Init();
	inline GLFWwindow* GetWindow();
	inline WindowMode GetWindowMode();
	inline bool ShouldWindowsClose();
	//void SwitchWindowMode();

	

}
