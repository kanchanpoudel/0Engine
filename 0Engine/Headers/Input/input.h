#pragma once
#include <map>

struct GLFWwindow;

namespace s00nya
{

	class Window;

	enum class Keys : int;
	enum class Buttons : int;
	enum class InputState : int;

	class Input
	{
	private:
		std::map<Keys, InputState> m_keyMaps;
		std::map<Buttons, InputState> m_buttonMaps;
		
		// first for x and second for y
		float m_cursorPosition[2];		// Ranges from 0.0f to window width or height
		float m_axesOffset[2];			// Ranges from -1.0f to 1.0f
		float m_scrollOffset[2];		// 1.0f for 1 line scroll

	private:
		/*
			Constructed by window through GetInputSystem() method
			because input events are connected to window
			Sets up all the callback for input system
		*/
		Input(GLFWwindow* window);

		// Should not be able to use default constructor, because window in needed for Input
		Input() = delete;
		// Input cannot be copied
		Input(const Input& input) = delete;
		Input& operator=(const Input& input) = delete;

	public:
		~Input();

	private:
		static void KeyCallback(GLFWwindow* window, int key, int scancodes, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void CursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
		static void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

	public:
		bool Pressed(const Keys& key);
		bool Held(const Keys& key);
		bool Repeated(const Keys& key);
		// Two key combination, e.g. [Ctrl] + [C]
		bool Combined(const Keys& hold, const Keys& press); 
		// Three key combination, e.g. [Ctrl] + [Shift] + [V]
		bool Combined(const Keys& hold1, const Keys& hold2, const Keys& press);

		bool Pressed(const Buttons& button);
		bool Held(const Buttons& button);
		// Mouse buttons do not have repeated event

		const float& CursorPositionX();
		const float& CursorPositionY();

		const float& HorizontalAxis();
		const float& VerticalAxis();

		const float& ScrollHorizontalAxis();
		const float& ScrollVerticalAxis();

		static const char* GetName(const Keys& key);
		static const char* GetName(const Buttons& button);

	private:
		static const char* GetInputName(const int& code);

		friend class Window;
	};

}