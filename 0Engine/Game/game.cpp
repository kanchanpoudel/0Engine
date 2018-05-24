#include "Game/game.h"
#include "Graphics/window.h"
#include "Debugger/logger.h"
#include "Utility/timer.h"
#include "Input/input.h"
#include "Input/input_manager.h"
#include "Utility/resource_manager.h"
#include "Game/locator.h"
#include "Physics/collider_sat.h"
#include "Physics/collision_sat.h"
#include "GameObject/game_object_2d.h"

namespace s00nya
{

	Game2D::Game2D(const Character* title, const Integer& width, const Integer& height) :
		window(Locator::Get().WindowService(title, width, height)),
		timer(Locator::Get().TimerService()),
		input(Locator::Get().InputService(window)),
		inputManager(Locator::Get().InputManagerService(input)),
		resource(Locator::Get().ResourceService()),
		renderer(Locator::Get().RendererService())
	{
		m_shaders["Default2DShader"] = Locator::Get().ShaderService("./Resources/default2dshader.glsl");
		instance = this;
	}

	Game2D::~Game2D()
	{
		delete m_shaders["Default2DShader"];

		m_shaders.clear();

		delete resource;
		delete inputManager;
		delete input;
		delete timer;
		delete window;
	}

	void Game2D::Start()
	{
		window->Show();

		// Time Management
		Float now = Timer::ElaspedTime();
		Float deltaTimeForSecond = 0.0f;
		
		while (window->IsRunning())
		{
			// Runs every 1 second
			if (Timer::ElaspedTime() - now > 1.0f)
			{
				now = Timer::ElaspedTime();
				Tick();
			}

			// As fast as possible
			Update();
			
			// Runs 60 times a second
			if (deltaTimeForSecond * fps > 1.0f)
			{
				deltaTimeForSecond = 0.0f;
				FixedUpdate();
			}

			// Sum up delta time to get total time difference
			deltaTimeForSecond += timer->DeltaTime();

			timer->Update();
			window->Update();
		}
	}

	void Game2D::Tick()
	{
		Debug::Log(true, true);
		printf("\nFPS : %d", (Integer)(1.0f / timer->DeltaTime()));
	}

	void Game2D::FixedUpdate()
	{
		/*for (auto& object : m_gameObjects)
			object.FixedUpdate();
		CollisionSAT::CollsionResolution(m_gameObjects);*/
	}

	void Game2D::Update()
	{
		/*for (auto& object : m_gameObjects)
			object.Update();*/
	}

	Input& Game2D::GetInput()
	{
		return *(instance->input);
	}

	Timer& Game2D::GetTimer()
	{
		return *(instance->timer);
	}

	InputManager& Game2D::GetInputManager()
	{
		return *(instance->inputManager);
	}

	Resources& Game2D::GetResourceManager()
	{
		return *(instance->resource);
	}

	const Float Game2D::fps = 60.0f;

	Game2D* Game2D::instance = nullptr;

}