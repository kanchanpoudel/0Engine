#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	class Debug;
	class Window;
	class Timer;
	class Input;
	class InputManager;
	class Locator;

	class S00NYA_API Locator
	{
	private:
		static Locator* instance;

	private:
		Locator();
		~Locator();

	public:
		Window* GetWindow(const Character* title, const Integer& width, const Integer& height) const;
		Timer* GetTimer() const;
		Input* GetInput(const Window* window) const;
		InputManager* GetInputManager(Input* input) const;

		static Locator& Get();
	};

}