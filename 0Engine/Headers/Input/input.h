#pragma once

struct GLFWwindow;

namespace s00nya
{

	class Window;

	class Input
	{
	private:
		static void Initialize(GLFWwindow* window); // Initialized when window is shown

	private:
		static void KeyCallBack(GLFWwindow* window, int key, int scancodes, int action, int mods);

		friend class Window;
	};

}