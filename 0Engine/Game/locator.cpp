#include "Game/locator.h"
#include "Debugger/logger.h"
#include "Graphics/window.h"
#include "Utility/timer.h"
#include "Input/input.h"
#include "Input/input_manager.h"
#include "Utility/resource_manager.h"

namespace s00nya
{

	Locator* Locator::instance(nullptr);

	Locator::Locator()
	{
	}

	Locator::~Locator()
	{
		if (instance)
		{
			Debug::ShutDown();
			delete instance;
		}
	}

	Window* Locator::WindowService(const Character* title, const Integer& width, const Integer& height) const
	{
		Window* temp = new Window(title, width, height);
		Debug::Initialize();
		return temp;
	}

	Timer* s00nya::Locator::TimerService() const
	{
		return new Timer();
	}

	Input* Locator::InputService(const Window* window) const
	{
		return new Input(window->m_id);
	}

	InputManager* Locator::InputManagerService(Input* input) const
	{
		return new InputManager(input);
	}

	Resources* Locator::ResourceService() const
	{
		return new Resources();
	}

	Locator& Locator::Get()
	{
		if (instance) return *instance;
		instance = new Locator();
		return *instance;
	}

}