#pragma once 

struct GLFWwindow;

namespace Lie
{
	class Window
	{
	private:
		GLFWwindow* m_id;
		int m_width;
		int m_height;
		bool m_fullscreen;

	public:
		Window(const char* title, const int& width, const int& height);
		~Window();

		Window(const Window& window) = delete;
		Window& operator=(const Window& window) = delete;

		void Close() const;
		void Update() const;
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