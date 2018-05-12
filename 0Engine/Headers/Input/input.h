#pragma once
#include <map>

struct GLFWwindow;

namespace s00nya
{

	class Window;

	enum class Keys : int;
	enum class Buttons : int;
	enum class InputState : int;

	class Input
	{
	private:
		std::map<Keys, InputState> m_keyMaps;
		std::map<Buttons, InputState> m_buttonMaps;
		
		// first for x and second for y
		float m_cursorPosition[2];		// Ranges from 0.0f to window width or height
		float m_axesOffset[2];			// Ranges from -1.0f to 1.0f
		float m_scrollOffset[2];		// 1.0f for 1 line scroll

	private:
		/*
			Constructed by window through GetInputSystem() method
			because input events are connected to window
			Sets up all the callback for input system
		*/
		Input(GLFWwindow* window);

	private:
		static void KeyCallback(GLFWwindow* window, int key, int scancodes, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void CursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
		static void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

	public:
		bool Pressed(Keys key);
		bool Held(Keys key);
		bool Repeated(Keys key);
		// Two key combination, e.g. [Ctrl] + [C]
		bool Combined(Keys hold, Keys press); 
		// Three key combination, e.g. [Ctrl] + [Shift] + [V]
		bool Combined(Keys hold1, Keys hold2, Keys press);

		bool Pressed(Buttons button);
		bool Held(Buttons button);
		// Mouse buttons do not have repeated event

		float CursorPositionX();
		float CursorPositionY();

		float HorizontalAxis();
		float VerticalAxis();

		float ScrollHorizontalAxis();
		float ScrollVerticalAxis();

		friend class Window;
	};

}