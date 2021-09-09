#pragma once
#ifndef INPUT_H
#define INPUT_H


//class Input {
//	/*enum InputType
//	{
//		SCROLL,
//		MOUSE,
//		KEYBOARD
//	};*/
//private:
//	Input() {}
//
//	static Input* GetReference() { return ref; }
//
//	//scroll
//	double xoffset, yoffset;
//	//mouse
//	double xpos, ypos;
//	//keyboard
//	int key, action;
//
//public:
//	static Input* ref;
//
//	static void ProcessInput();
//	
//	void SetKeyboard(int key, int action);
//	void SetScroll(double xoffset, double yoffset);
//	void SetMouse(double xpos, double ypos);
//	//static Input inst;
//
//};

namespace Input {
	void ProcessInput();
	void SetKeyboard(int key, int action);
	void SetScroll(double xoffset, double yoffset);
	void SetMouse(double xpos, double ypos);
}
#endif // !INPUT_H
