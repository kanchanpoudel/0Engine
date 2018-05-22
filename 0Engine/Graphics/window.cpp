#include "Graphics/window.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Debugger/logger.h"
#include "Input/input.h"
#include <string>

namespace s00nya
{
	
	Window::Window(const Character* title, const Integer& width, const Integer& height) :
		m_id(nullptr), m_width(width), m_height(height), m_fullscreen(false)
	{
		glfwInit();

		//Setting up window properties
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef ENGINE_DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

		//If WINDOW_AUTO_ is passed then set width and height of the monitor
		const GLFWvidmode* monitorProp = glfwGetVideoMode(glfwGetPrimaryMonitor());
		if (width == WINDOW_AUTO_WIDTH)
			m_width = monitorProp->width;
		else
			m_width = width;
		if (height == WINDOW_AUTO_HEIGHT)
			m_height = monitorProp->height;
		else
			m_height = height;

		m_id = glfwCreateWindow(m_width, m_height, title, nullptr, nullptr);
		if (!m_id)
			Debug::Add("GLFW | Window Pointer Empty", Debug::S00NYA_LOG_ERROR);

		glfwMakeContextCurrent(m_id);
		glewInit();	// Loading OpenGL function pointers
		Debug::Add("OPENGL | Vendor=" +
			std::string((char*)glGetString(GL_VENDOR)) +
			" Version=" + std::string((char*)glGetString(GL_VERSION)), Debug::S00NYA_LOG_INFO);

		glfwSetWindowAspectRatio(m_id, m_width, m_height);
		glViewport(0, 0, m_width, m_height);
	}

	Input* Window::GetInputSystem() const
	{
		return new Input(m_id);
	}
	
	Window::~Window()
	{
		glfwDestroyWindow(m_id);
		glfwTerminate();
	}

	void Window::Show() const
	{
		glfwShowWindow(m_id);
	}

	void Window::Update() const
	{
		glfwSwapBuffers(m_id);
		glfwPollEvents();
	}

	void Window::Close() const
	{
		glfwSetWindowShouldClose(m_id, true);
	}

	bool Window::IsRunning() const
	{
		return !glfwWindowShouldClose(m_id);
	}

	void Window::Resize(const Integer& width, const Integer& height)
	{
		//If WINDOW_AUTO_ is passed then set width and height of the monitor
		const GLFWvidmode* monitorProp = glfwGetVideoMode(glfwGetPrimaryMonitor());
		if (width == WINDOW_AUTO_WIDTH)
			m_width = monitorProp->width;
		else
			m_width = width;
		if (height == WINDOW_AUTO_HEIGHT)
			m_height = monitorProp->height;
		else 
			m_height = height;
		
		glfwSetWindowAspectRatio(m_id, m_width, m_height);
		glfwSetWindowSize(m_id, m_width, m_height);
		glViewport(0, 0, m_width, m_height);
	}

	void Window::ToggleFullscreen()
	{
		if (m_fullscreen)
		{
			/*When changing from full screen to windowed mode,
			  we need to position to place the window in the monitor
			  so we calculate the position such that full window is shown in monitor
			  */
			const GLFWvidmode* monitorProp = glfwGetVideoMode(glfwGetPrimaryMonitor());
			Integer posX = (monitorProp->width >> 1) - (m_width >> 1);		// Division by 2 is equivalent to right shift by 1
			Integer posY = (monitorProp->height >> 1) - (m_height >> 1);	// Division by 2 is equivalent to right shift by 1
			glfwSetWindowMonitor(m_id, nullptr, posX, posY, m_width, m_height, GLFW_DONT_CARE); // GLFW_DONT_CARE disables VSync
		}
		else
			glfwSetWindowMonitor(m_id, glfwGetPrimaryMonitor(), 0, 0, m_width, m_height, GLFW_DONT_CARE); // GLFW_DONT_CARE disables VSync
		
		m_fullscreen = !m_fullscreen;
	}

	void Window::ChangeCursor(const Character* cursorPath) const
	{
		// TO-DO
	}

	void Window::SetIcon(const Character* iconPath) const
	{
		// TO-DO
	}

	void Window::DisableCursor() const
	{
		glfwSetInputMode(m_id, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void Window::HideCursor() const
	{
		glfwSetInputMode(m_id, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}

	void Window::EnableCursor() const
	{
		glfwSetInputMode(m_id, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

}