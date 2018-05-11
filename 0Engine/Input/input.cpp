#include "Input/input.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace s00nya
{

	void Input::Initialize(GLFWwindow* window)
	{
		glfwSetKeyCallback(window, Input::KeyCallBack);
	}

}