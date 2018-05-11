#pragma once

struct GLFWwindow;

namespace s00nya
{

	class Window;

	class Input
	{
	private:
		/*
			Initialized when window is shown
			Sets up all the callback for input system
		*/
		static void Initialize(GLFWwindow* window);

	private:
		static void KeyCallback(GLFWwindow* window, int key, int scancodes, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int modes);
		static void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
		static void CursorPositionCallback(GLFWwindow* window, double xPos, double yPos);

		friend class Window;
	};

}