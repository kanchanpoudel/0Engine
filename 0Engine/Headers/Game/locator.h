#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	class Debug;
	class Window;
	class Timer;
	class Input;
	class InputManager;
	class EventManager;
	class Resources;
	class Locator;

	class S00NYA_API Locator
	{
	private:
		static Locator* instance;

	private:
		Locator();
		~Locator();

	public:
		Window* WindowService(const Character* title, const Integer& width, const Integer& height) const;
		Timer* TimerService() const;
		Input* InputService(const Window* window) const;
		InputManager* InputManagerService(Input* input) const;
		EventManager* EventManagerService() const;
		Resources* ResourceService() const;
		

		static Locator& Get();
	};

}