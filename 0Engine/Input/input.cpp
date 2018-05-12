#include "Input\inputvalues.h"
#include "Input\inputactions.h"
#include "Input\input.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace s00nya
{

	std::map<Keys, InputState> Input::m_keyMaps
	{
		{ Keys::UNKNOWN, InputState::UP },

		{ Keys::SPACE, InputState::UP },
		{ Keys::APOSTROPHE, InputState::UP },
		{ Keys::COMMA, InputState::UP },
		{ Keys::MINUS, InputState::UP },
		{ Keys::PERIOD, InputState::UP },
		{ Keys::SLASH, InputState::UP },

		{ Keys::NUM_0, InputState::UP },
		{ Keys::NUM_1, InputState::UP },
		{ Keys::NUM_2, InputState::UP },
		{ Keys::NUM_3, InputState::UP },
		{ Keys::NUM_4, InputState::UP },
		{ Keys::NUM_5, InputState::UP },
		{ Keys::NUM_6, InputState::UP },
		{ Keys::NUM_7, InputState::UP },
		{ Keys::NUM_8, InputState::UP },
		{ Keys::NUM_9, InputState::UP },

		{ Keys::SEMICOLON, InputState::UP },
		{ Keys::EQUAL, InputState::UP },

		{ Keys::ALPAHBET_A, InputState::UP },
		{ Keys::ALPAHBET_B, InputState::UP },
		{ Keys::ALPAHBET_C, InputState::UP },
		{ Keys::ALPAHBET_D, InputState::UP },
		{ Keys::ALPAHBET_E, InputState::UP },
		{ Keys::ALPAHBET_F, InputState::UP },
		{ Keys::ALPAHBET_G, InputState::UP },
		{ Keys::ALPAHBET_H, InputState::UP },
		{ Keys::ALPAHBET_I, InputState::UP },
		{ Keys::ALPAHBET_J, InputState::UP },
		{ Keys::ALPAHBET_K, InputState::UP },
		{ Keys::ALPAHBET_L, InputState::UP },
		{ Keys::ALPAHBET_M, InputState::UP },
		{ Keys::ALPAHBET_N, InputState::UP },
		{ Keys::ALPAHBET_O, InputState::UP },
		{ Keys::ALPAHBET_P, InputState::UP },
		{ Keys::ALPAHBET_Q, InputState::UP },
		{ Keys::ALPAHBET_R, InputState::UP },
		{ Keys::ALPAHBET_S, InputState::UP },
		{ Keys::ALPAHBET_T, InputState::UP },
		{ Keys::ALPAHBET_U, InputState::UP },
		{ Keys::ALPAHBET_V, InputState::UP },
		{ Keys::ALPAHBET_W, InputState::UP },
		{ Keys::ALPAHBET_X, InputState::UP },
		{ Keys::ALPAHBET_Y, InputState::UP },
		{ Keys::ALPAHBET_Z, InputState::UP },

		{ Keys::LEFT_BRACKET, InputState::UP },
		{ Keys::BACKSLASH, InputState::UP },
		{ Keys::RIGHT_BRACKET, InputState::UP },
		{ Keys::GRAVE_ACCENT, InputState::UP },
		{ Keys::WORLD_1, InputState::UP },
		{ Keys::WORLD_2, InputState::UP },
		{ Keys::ESCAPE, InputState::UP },
		{ Keys::ENTER, InputState::UP },
		{ Keys::TAB, InputState::UP },
		{ Keys::BACKSPACE, InputState::UP },
		{ Keys::INSERT, InputState::UP },
		{ Keys::DELETE, InputState::UP },

		{ Keys::DIRECTIONAL_RIGHT, InputState::UP },
		{ Keys::DIRECTIONAL_LEFT, InputState::UP },
		{ Keys::DIRECTIONAL_DOWN, InputState::UP },
		{ Keys::DIRECTIONAL_UP, InputState::UP },

		{ Keys::PAGE_UP, InputState::UP },
		{ Keys::PAGE_DOWN, InputState::UP },
		{ Keys::HOME, InputState::UP },
		{ Keys::END, InputState::UP },
		{ Keys::CAPS_LOCK, InputState::UP },
		{ Keys::SCROLL_LOCK, InputState::UP },
		{ Keys::NUM_LOCK, InputState::UP },
		{ Keys::PRINT_SCREEN, InputState::UP },
		{ Keys::PAUSE, InputState::UP },

		{ Keys::F1, InputState::UP },
		{ Keys::F2, InputState::UP },
		{ Keys::F3, InputState::UP },
		{ Keys::F4, InputState::UP },
		{ Keys::F5, InputState::UP },
		{ Keys::F6, InputState::UP },
		{ Keys::F7, InputState::UP },
		{ Keys::F8, InputState::UP },
		{ Keys::F9, InputState::UP },
		{ Keys::F10, InputState::UP },
		{ Keys::F11, InputState::UP },
		{ Keys::F12, InputState::UP },
		{ Keys::F13, InputState::UP },
		{ Keys::F14, InputState::UP },
		{ Keys::F15, InputState::UP },
		{ Keys::F16, InputState::UP },
		{ Keys::F17, InputState::UP },
		{ Keys::F18, InputState::UP },
		{ Keys::F19, InputState::UP },
		{ Keys::F20, InputState::UP },
		{ Keys::F21, InputState::UP },
		{ Keys::F22, InputState::UP },
		{ Keys::F23, InputState::UP },
		{ Keys::F24, InputState::UP },
		{ Keys::F25, InputState::UP },

		{ Keys::NUM_PAD_0, InputState::UP },
		{ Keys::NUM_PAD_1, InputState::UP },
		{ Keys::NUM_PAD_2, InputState::UP },
		{ Keys::NUM_PAD_3, InputState::UP },
		{ Keys::NUM_PAD_4, InputState::UP },
		{ Keys::NUM_PAD_5, InputState::UP },
		{ Keys::NUM_PAD_6, InputState::UP },
		{ Keys::NUM_PAD_7, InputState::UP },
		{ Keys::NUM_PAD_8, InputState::UP },
		{ Keys::NUM_PAD_9, InputState::UP },

	{ Keys::NUM_PAD_DECIMAL, InputState::UP },
	{ Keys::NUM_PAD_DIVIDE, InputState::UP },
	{ Keys::NUM_PAD_MULTIPLY, InputState::UP },
	{ Keys::NUM_PAD_SUBTRACT, InputState::UP },
	{ Keys::NUM_PAD_ADD, InputState::UP },
	{ Keys::NUM_PAD_ENTER, InputState::UP },
	{ Keys::NUM_PAD_EQUAL, InputState::UP },
	{ Keys::LEFT_SHIFT, InputState::UP },
	{ Keys::LEFT_CONTROL, InputState::UP },
	{ Keys::LEFT_ALT, InputState::UP },
	{ Keys::LEFT_SUPER, InputState::UP },
	{ Keys::RIGHT_SHIFT, InputState::UP },
	{ Keys::RIGHT_CONTROL, InputState::UP },
	{ Keys::RIGHT_ALT, InputState::UP },
	{ Keys::RIGHT_SUPER, InputState::UP },
	{ Keys::MENU, InputState::UP }
	};

	std::map<Buttons, InputState> Input::m_buttonMaps
	{
		{ Buttons::MOUSE_LEFT_CLICK, InputState::UP },
		{ Buttons::MOUSE_RIGHT_CLICK, InputState::UP },
		{ Buttons::MOUSE_MIDDLE_CLICK, InputState::UP },

		{ Buttons::MOUSE_BUTTON_1, InputState::UP },
		{ Buttons::MOUSE_BUTTON_2, InputState::UP },
		{ Buttons::MOUSE_BUTTON_3, InputState::UP },
		{ Buttons::MOUSE_BUTTON_4, InputState::UP },
		{ Buttons::MOUSE_BUTTON_5, InputState::UP }
	};

	float Input::m_cursorPosition[2]{ 0.0f, 0.0f };
	float Input::m_scrollOffset[2]{ 0.0f, 0.0f };

	void Input::Initialize(GLFWwindow* window)
	{
		glfwSetKeyCallback(window, Input::KeyCallback);
		glfwSetMouseButtonCallback(window, Input::MouseButtonCallback);
		glfwSetCursorPosCallback(window, Input::CursorPositionCallback);
		glfwSetScrollCallback(window, Input::ScrollCallback);
	}

	void Input::KeyCallback(GLFWwindow* window, int key, int scancodes, int action, int mods)
	{
		Keys keyCode = (Keys)key;

		switch (action)
		{
		case GLFW_PRESS:
			Input::m_keyMaps[keyCode] = InputState::DOWN;
			return;
		case GLFW_REPEAT:
			Input::m_keyMaps[keyCode] = InputState::REPEATED;
			return;
		}

		if (Input::m_keyMaps[keyCode] == InputState::DOWN && action == GLFW_RELEASE)
		{
			Input::m_keyMaps[keyCode] = InputState::PRESSED;
			return;
		}
		else
			Input::m_keyMaps[keyCode] = InputState::UP;
	}

	void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		Buttons buttonCode = (Buttons)button;

		if (action == GLFW_PRESS)
		{
			Input::m_buttonMaps[buttonCode] = InputState::DOWN;
			return;
		}

		if (Input::m_buttonMaps[buttonCode] == InputState::DOWN && action == GLFW_RELEASE)
		{
			Input::m_buttonMaps[buttonCode] = InputState::PRESSED;
			return;
		}
		else
			Input::m_buttonMaps[buttonCode] = InputState::UP;
	}

	void Input::CursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
	{
		int winWidth, winHeight;
		glfwGetWindowSize(window, &winWidth, &winHeight);

		Input::m_cursorPosition[0] = (float)xPos;
		Input::m_cursorPosition[1] = winHeight - (float)yPos;
	}

	void Input::ScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{

	}

	bool Input::Pressed(Keys key)
	{
		if (Input::m_keyMaps[key] == InputState::PRESSED)
		{
			Input::m_keyMaps[key] = InputState::UP;
			return true;
		}
		return false;
	}

	bool Input::Held(Keys key)
	{
		return Input::m_keyMaps[key] == InputState::DOWN;
	}

	bool Input::Repeated(Keys key)
	{
		return Input::m_keyMaps[key] == InputState::REPEATED;
	}

	bool Input::Pressed(Buttons button)
	{
		if (Input::m_buttonMaps[button] == InputState::PRESSED)
		{
			Input::m_buttonMaps[button] = InputState::UP;
			return true;
		}
		return false;
	}

	bool Input::Held(Buttons button)
	{
		return Input::m_buttonMaps[button] == InputState::DOWN;
	}

	float Input::CursorPositionX()
	{
		return m_cursorPosition[0];
	}

	float Input::CursorPositionY()
	{
		return m_cursorPosition[1];
	}

}