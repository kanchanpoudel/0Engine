#include "Game/timer.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace s00nya
{

	Timer::Timer() :
		m_lastFrameTime(0.0f)
	{
	}

	float Timer::DeltaTime() const
	{
		return (float)glfwGetTime() - m_lastFrameTime;
	}

	float Timer::ElaspedTime()
	{
		return (float)glfwGetTime();
	}

	void Timer::Update()
	{
		m_lastFrameTime = (float)glfwGetTime();
	}

}