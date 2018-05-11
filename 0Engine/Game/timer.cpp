#include "Game\timer.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace s00nya
{

	float Timer::m_s_lastFrameTime = 0.0f;

	float Timer::ElaspedTime()
	{
		return (float)glfwGetTime();
	}

	float Timer::DeltaTime()
	{
		return (float)glfwGetTime() - m_s_lastFrameTime;
	}

	void Timer::Update()
	{
		m_s_lastFrameTime = (float)glfwGetTime();
	}

}