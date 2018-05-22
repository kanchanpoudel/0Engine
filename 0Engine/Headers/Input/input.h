#pragma once
#include <map>
#include "s00nya_defs.h"

struct GLFWwindow;

namespace s00nya
{

	class Window;
	class Locator;

	enum class Keys : Integer;
	enum class Buttons : Integer;
	enum class InputState : Integer;

	class S00NYA_API Input
	{
	private:
		std::map<Keys, InputState> m_keyMaps;
		std::map<Buttons, InputState> m_buttonMaps;
		
		// first for x and second for y
		Float m_cursorPosition[2];		// Ranges from 0.0f to window width or height
		Float m_axesOffset[2];			// Ranges from -1.0f to 1.0f
		Float m_scrollOffset[2];		// 1.0f for 1 line scroll

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
		static void KeyCallback(GLFWwindow* window, Integer key, Integer scancodes, Integer action, Integer mods);
		static void MouseButtonCallback(GLFWwindow* window, Integer button, Integer action, Integer mods);
		static void CursorPositionCallback(GLFWwindow* window, Double xPos, Double yPos);
		static void ScrollCallback(GLFWwindow* window, Double xOffset, Double yOffset);

	public:
		Boolean Pressed(const Keys& key);
		Boolean Held(const Keys& key);
		Boolean Repeated(const Keys& key);
		// Two key combination, e.g. [Ctrl] + [C]
		Boolean Combined(const Keys& hold, const Keys& press);
		// Three key combination, e.g. [Ctrl] + [Shift] + [V]
		Boolean Combined(const Keys& hold1, const Keys& hold2, const Keys& press);

		Boolean Pressed(const Buttons& button);
		Boolean Held(const Buttons& button);
		// Mouse buttons do not have repeated event

		const Float& CursorPositionX();
		const Float& CursorPositionY();

		const Float& HorizontalAxis();
		const Float& VerticalAxis();

		const Float& ScrollHorizontalAxis();
		const Float& ScrollVerticalAxis();

		static const Character* GetName(const Keys& key);
		static const Character* GetName(const Buttons& button);

	private:
		static const Character* GetInputName(const Integer& code);

		friend class Window;
		friend class Locator;
	};

}