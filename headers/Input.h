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
    namespace Keys {
        enum Key {
            W, A, S, D,
            TAB,
            MOUSE1,
            LSHIFT
        };
    }
	void ProcessInput();
    bool IsPressed(Keys::Key key);
	void SetKeyboard(int key, int action);
	void SetScroll(double xoffset, double yoffset);
	void SetMouse(double xpos, double ypos);
}

namespace Keys {
    
}
#endif // !INPUT_H
