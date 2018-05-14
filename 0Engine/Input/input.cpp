#include "Input/input_values.h"
#include "Input/input_actions.h"
#include "Input/input.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

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

	Input::~Input()
	{

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
		currentInput->m_scrollOffset[0] = (float)xOffset;
		currentInput->m_scrollOffset[1] = (float)yOffset;
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

	const char* Input::GetName(const Keys& key)
	{
		return GetInputName((int)key);
	}

	const char* Input::GetName(const Buttons& button)
	{
		return GetInputName((int)button);
	}

	const char* Input::GetInputName(const int& code)
	{
		switch (code)
		{
		case 0: return "Left Click";
		case 1: return "Right Click";
		case 2: return "Middle Click";

		case 32: return "Space";
		case 39: return "'";
		case 44: return ",";
		case 45: return "-";
		case 46: return ".";
		case 47: return "/";

		case 48: return " 0";
		case 49: return " 1";
		case 50: return " 2";
		case 51: return " 3";
		case 52: return " 4";
		case 53: return " 5";
		case 54: return " 6";
		case 55: return " 7";
		case 56: return " 8";
		case 57: return " 9";

		case 59: return ";";
		case 61: return "=";

		case 65: return "A";
		case 66: return "B";
		case 67: return "C";
		case 68: return "D";
		case 69: return "E";
		case 70: return "F";
		case 71: return "G";
		case 72: return "H";
		case 73: return "I";
		case 74: return "J";
		case 75: return "K";
		case 76: return "L";
		case 77: return "M";
		case 78: return "N";
		case 79: return "O";
		case 80: return "P";
		case 81: return "Q";
		case 82: return "R";
		case 83: return "S";
		case 84: return "T";
		case 85: return "U";
		case 86: return "V";
		case 87: return "W";
		case 88: return "X";
		case 89: return "Y";
		case 90: return "Z";

		case 91: return "[";
		case 92: return "\\";
		case 93: return "]";
		case 96: return "`";
		case 256: return "Escape";
		case 257: return "Enter";
		case 258: return "Tab";
		case 259: return "Backspace";
		case 260: return "Insert";
		case 261: return "Delete";

		case 262: return "Right";
		case 263: return "Left";
		case 264: return "Down";
		case 265: return "Up";

		case 266: return "Page Up";
		case 267: return "Page Down";
		case 268: return "Home";
		case 269: return "End";
		case 280: return "Caps Lock";
		case 281: return "Scroll Lock";
		case 282: return "Num Lock";
		case 283: return "Print Screen Sys Req";
		case 284: return "Pause";

		case 290: return "F1";
		case 291: return "F2";
		case 292: return "F3";
		case 293: return "F4";
		case 294: return "F5";
		case 295: return "F6";
		case 296: return "F7";
		case 297: return "F8";
		case 298: return "F9";
		case 299: return "F10";
		case 300: return "F11";
		case 301: return "F12";
		case 302: return "F13";
		case 303: return "F14";
		case 304: return "F15";
		case 305: return "F16";
		case 306: return "F17";
		case 307: return "F18";
		case 308: return "F19";
		case 309: return "F20";
		case 310: return "F21";
		case 311: return "F22";
		case 312: return "F23";
		case 313: return "F24";
		case 314: return "F25";

		case 320: return " 0";
		case 321: return " 1";
		case 322: return " 2";
		case 323: return " 3";
		case 324: return " 4";
		case 325: return " 5";
		case 326: return " 6";
		case 327: return " 7";
		case 328: return " 8";
		case 329: return " 9";

		case 330: return ".";
		case 331: return "/";
		case 332: return "*";
		case 333: return "-";
		case 334: return "+";
		case 335: return "Enter";
		case 336: return "=";
		case 340: return "Left Shift";
		case 341: return "Left Control";
		case 342: return "Left Alt";
		case 343: return "Left Super";
		case 344: return "Right Shift";
		case 345: return "Right Control";
		case 346: return "Right Alt";
		case 347: return "Right Super";
		case 348: return "Menu";

		default:
			return "Unknown";
		}
	}

}