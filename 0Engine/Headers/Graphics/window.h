#pragma once 

struct GLFWwindow;

namespace s00nya
{

	class Input;

	class Window
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

	public:
		Window(const char* title, const int& width, const int& height);
		~Window();

		Window(const Window& window) = delete;
		Window& operator=(const Window& window) = delete;

		Input* GetInputSystem() const; // Constructs Input class in heap
		void Show() const;
		void Update() const;

		void Close() const;
		bool IsRunning() const;

		void Resize(const int& width, const int& height);
		void ToggleFullscreen();

		void ChangeCursor(const char* path) const;
		void SetIcon(const char* path) const;
		void DisableCursor() const;
		void HideCursor() const;
		void EnableCursor() const;
	};

}