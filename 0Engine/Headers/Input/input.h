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
		static std::map<Keys, InputState> m_keyMaps;
		static std::map<Buttons, InputState> m_buttonMaps;
		
		// first for x and second for y
		static float m_cursorPosition[2];	// Ranges from 0.0f to window width or height
		static float m_axesOffset[2];		// Ranges from -1.0f to 1.0f
		static float m_scrollOffset[2];		// Ranges from -1.0f to 1.0f

	private:
		/*
			Initialized when window is shown
			Sets up all the callback for input system
		*/
		static void Initialize(GLFWwindow* window);

	private:
		static void KeyCallback(GLFWwindow* window, int key, int scancodes, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void CursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
		static void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

	public:
		static bool Pressed(Keys key);
		static bool Held(Keys key);
		static bool Repeated(Keys key);

		static bool Pressed(Buttons button);
		static bool Held(Buttons button);

		static float CursorPositionX();
		static float CursorPositionY();

		static float HorizontalAxis();
		static float VerticalAxis();

		friend class Window;
	};

}