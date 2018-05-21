#include "Utility/timer.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace s00nya
{

	Timer::Timer() :
		m_lastFrameTime(0.0f)
	{
	}

	Float Timer::DeltaTime() const
	{
		return (Float)glfwGetTime() - m_lastFrameTime;
	}

	Float Timer::ElaspedTime()
	{
		return (Float)glfwGetTime();
	}

	void Timer::Update()
	{
		m_lastFrameTime = (Float)glfwGetTime();
	}

}