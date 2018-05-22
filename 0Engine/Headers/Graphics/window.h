#pragma once
#include "s00nya_defs.h"

struct GLFWwindow;

namespace s00nya
{

	class Input;
	class Locator;

	class S00NYA_API Window
	{
	private:
		GLFWwindow* m_id;
		int m_width;
		int m_height;
		bool m_fullscreen;

	public:
		enum 
		{ 
			WINDOW_AUTO_WIDTH = -1,
			WINDOW_AUTO_HEIGHT = -2
		};

	private:
		Window(const Character* title, const Integer& width, const Integer& height);
		Input* GetInputSystem() const; // Constructs Input class in heap
	
	public:
		~Window();

	private:
		Window(const Window& window) = delete;
		Window& operator=(const Window& window) = delete;

	public:
		void Show() const;
		void Update() const;

		void Close() const;
		bool IsRunning() const;

		void Resize(const Integer& width, const Integer& height);
		void ToggleFullscreen();

		void ChangeCursor(const Character* path) const;
		void SetIcon(const Character* path) const;
		void DisableCursor() const;
		void HideCursor() const;
		void EnableCursor() const;

		friend class Locator;
	};

}