#pragma once
#include "s00nya_defs.h"

struct GLFWwindow;
struct GLFWcursor;

namespace s00nya
{

	class Game2D;
	class Input;
	struct RawImage;

	class S00NYA_API Window
	{
	private:
		GLFWwindow* m_id;
		GLFWcursor* m_cursor;
		Integer m_width;
		Integer m_height;
		Boolean m_fullscreen;

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

		void Show() const;
		void Update() const;

		void Close() const;
		bool IsRunning() const;

	public:
		void Resize(const Integer& width, const Integer& height);
		void ToggleFullscreen();

		void ChangeCursor(const RawImage& image);
		void SetIcon(const RawImage& image);
		void DisableCursor() const;
		void HideCursor() const;
		void EnableCursor() const;

		const Integer& Width() const;
		const Integer& Height() const;

		friend class Game2D;
	};

}