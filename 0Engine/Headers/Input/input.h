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

		friend class Window;
	};

}