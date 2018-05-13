#include "Input\inputvalues.h"
#include "Input\inputactions.h"
#include "Input\input.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace s00nya
{

	Input::Input(GLFWwindow* window) :

		// Assuming at the start of the program for all keys to be UP / not held
		m_keyMaps
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
	},

		// Assuming at the start of the program for all mouse buttons to be UP / not held
		m_buttonMaps
	{
		{ Buttons::MOUSE_LEFT_CLICK, InputState::UP },
		{ Buttons::MOUSE_RIGHT_CLICK, InputState::UP },
		{ Buttons::MOUSE_MIDDLE_CLICK, InputState::UP },

		{ Buttons::MOUSE_BUTTON_1, InputState::UP },
		{ Buttons::MOUSE_BUTTON_2, InputState::UP },
		{ Buttons::MOUSE_BUTTON_3, InputState::UP },
		{ Buttons::MOUSE_BUTTON_4, InputState::UP },
		{ Buttons::MOUSE_BUTTON_5, InputState::UP }
	},

		// Assuming at the start of the program everything to be zero
		m_cursorPosition{ 0.0f, 0.0f },
		m_axesOffset{ 0.0f, 0.0f },
		m_scrollOffset{ 0.0f, 0.0f }
	{
		// Give GLFW this pointer so that we can access that in callback functions
		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, Input::KeyCallback);
		glfwSetMouseButtonCallback(window, Input::MouseButtonCallback);
		glfwSetCursorPosCallback(window, Input::CursorPositionCallback);
		glfwSetScrollCallback(window, Input::ScrollCallback);
	}

	void Input::KeyCallback(GLFWwindow* window, int key, int scancodes, int action, int mods)
	{
		const Keys& keyCode = (Keys)key;
		// Get the instance of Input class associated with the window
		Input* currentInput = (Input*)glfwGetWindowUserPointer(window);

		// If the key is currently held / repeatedly pressed, process first
		switch (action)
		{
		case GLFW_PRESS:
			currentInput->m_keyMaps[keyCode] = InputState::DOWN;
			return;
		case GLFW_REPEAT:
			currentInput->m_keyMaps[keyCode] = InputState::REPEATED;
			return;
		}

		// If the key was previously held and now released,then the key is pressed
		if (currentInput->m_keyMaps[keyCode] == InputState::DOWN && action == GLFW_RELEASE)
		{
			currentInput->m_keyMaps[keyCode] = InputState::PRESSED;
			return;
		}
		else // the key is neither pressed or held means it is not held / UP
			currentInput->m_keyMaps[keyCode] = InputState::UP;
	}

	void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		const Buttons& buttonCode = (Buttons)button;
		// Get the instance of Input class associated with the window
		Input* currentInput = (Input*)glfwGetWindowUserPointer(window);

		// If the button is currently held, process first
		if (action == GLFW_PRESS) // Mouse buttons do not have repeated events
		{
			currentInput->m_buttonMaps[buttonCode] = InputState::DOWN;
			return;
		}

		// If the button was previously held and now released,then the key is pressed
		if (currentInput->m_buttonMaps[buttonCode] == InputState::DOWN && action == GLFW_RELEASE)
		{
			currentInput->m_buttonMaps[buttonCode] = InputState::PRESSED;
			return;
		}
		else // the key is neither pressed or held means it is not held / UP
			currentInput->m_buttonMaps[buttonCode] = InputState::UP;
	}

	void Input::CursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
	{
		// Get the instance of Input class associated with the window
		Input* currentInput = (Input*)glfwGetWindowUserPointer(window);

		// We need window screen width and height to map the offset to -1.0f to 1.0f
		int winWidth, winHeight;
		glfwGetWindowSize(window, &winWidth, &winHeight);

		/*
			Mapping the offset to -1.0f to 1.0f,
			multiplied by 10.0f because value ranges in the order 1e-2
		*/
		currentInput->m_axesOffset[0] =
			((float)xPos - currentInput->m_cursorPosition[0]) / winWidth * 10.0f;
		currentInput->m_axesOffset[1] =
			(currentInput->m_cursorPosition[1] + (float)yPos - (float)winHeight) / winHeight * 10.0f;

		currentInput->m_cursorPosition[0] = (float)xPos;
		/*
			Because we are using the Right Hand Co-ordinate system
			where y starts from bottom to top, but windows gives us
			Left Hand Co-ordinate system's y value, so changing handness
		*/
		currentInput->m_cursorPosition[1] = winHeight - (float)yPos;
	}

	void Input::ScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		// Get the instance of Input class associated with the window
		Input* currentInput = (Input*)glfwGetWindowUserPointer(window);
		currentInput->m_scrollOffset[0] = xOffset;
		currentInput->m_scrollOffset[1] = yOffset;
	}

	bool Input::Pressed(const Keys& key)
	{
		if (m_keyMaps[key] == InputState::PRESSED)
		{
			/*
				Once the Pressing event is accessed,
				the key should be reset to UP / not held state
				because the key was already released, we store
				Pressed event when key is released
			*/
			m_keyMaps[key] = InputState::UP;
			return true;
		}
		return false;
	}

	bool Input::Held(const Keys& key)
	{
		return m_keyMaps[key] == InputState::DOWN;
	}

	bool Input::Repeated(const Keys& key)
	{
		return m_keyMaps[key] == InputState::REPEATED;
	}

	bool Input::Combined(const Keys& hold, const Keys& press)
	{
		/*
			First Pressing event is checked because
			Pressing events are cleared only after Pressed() is called.
			So if Holding events is checked first, and the user presses and
			then later holds the hold key, then this function will return true
			which for that case we wouldn't want
		*/
		if (m_keyMaps[press] == InputState::PRESSED &&
			m_keyMaps[hold] == InputState::DOWN)
		{
			// Since Pressed event is used, we need to clear the key state
			m_keyMaps[press] = InputState::UP;
			return true;
		}

		return false;
	}

	bool Input::Combined(const Keys& hold1, const Keys& hold2, const Keys& press)
	{
		/*
		First Pressing event is checked because
		Pressing events are cleared only after Pressed() is called.
		So if Holding events is checked first, and the user presses and
		then later holds the hold key, then this function will return true
		which for that case we wouldn't want
		*/
		if (m_keyMaps[press] == InputState::PRESSED &&
			m_keyMaps[hold1] == InputState::DOWN &&
			m_keyMaps[hold2] == InputState::DOWN)
		{
			// Since Pressed event is used, we need to clear the key state
			m_keyMaps[press] = InputState::UP;
			return true;
		}
		return false;
	}

	bool Input::Pressed(const Buttons& button)
	{
		if (m_buttonMaps[button] == InputState::PRESSED)
		{
			/*
			Once the Pressing event is accessed,
			the button should be reset to UP / not held state
			because the button was already released, we store
			Pressed event when button is released
			*/
			m_buttonMaps[button] = InputState::UP;
			return true;
		}
		return false;
	}

	bool Input::Held(const Buttons& button)
	{
		return m_buttonMaps[button] == InputState::DOWN;
	}

	const float& Input::CursorPositionX()
	{
		return m_cursorPosition[0];
	}

	const float& Input::CursorPositionY()
	{
		return m_cursorPosition[1];
	}

	const float& Input::HorizontalAxis()
	{
		const float& ha = m_axesOffset[0];
		/*
			Once the offset is called for we want to clear offset
			because Axes offsets do not have callbacks
		*/
		m_axesOffset[0] = 0.0f;
		return ha;
	}

	const float& Input::VerticalAxis()
	{
		const float& va = m_axesOffset[1];
		/*
		Once the offset is called for we want to clear offset
		because Axes offsets do not have callbacks
		*/
		m_axesOffset[1] = 0.0f;
		return va;
	}

	const float& Input::ScrollHorizontalAxis()
	{
		return m_scrollOffset[0];
	}

	const float& Input::ScrollVerticalAxis()
	{
		return m_scrollOffset[1];
	}

}