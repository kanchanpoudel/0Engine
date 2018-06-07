#include "Game/game.h"
#include "Graphics/window.h"
#include "Debugger/logger.h"
#include "Utility/timer.h"
#include "Input/input.h"
#include "Input/input_manager.h"
#include "Utility/resource_manager.h"
#include "Utility/events.h"
#include "Utility/event_manager.h"
#include "Physics/collision_2d.h"
#include "GameObject/scene_2d.h"
#include "GameObject/game_object_2d.h"
#include "Graphics/renderer.h"
#include "GL/glew.h"
#include "Game/locator.h"

namespace s00nya
{

	Game2D::Game2D(const Character* title, const Integer& width, const Integer& height, const Samples& sample) :
		window(Locator::Get().WindowService(title, width, height)),
		timer(Locator::Get().TimerService()),
		input(Locator::Get().InputService(window)),
		inputManager(Locator::Get().InputManagerService(input)),
		eventManager(Locator::Get().EventManagerService()),
		resource(Locator::Get().ResourceService()),
		renderer(Locator::Get().RendererService(
			window->Width() * (Integer)sample, 
			window->Height() * (Integer)sample, 
			window->Width(),
			window->Height()
		))
	{
		m_shaders["Default2DShader"] = Locator::Get().ShaderService("./Resources/Default2DShader.glsl");
		m_shaders["DefaultPostprocessingShader"] = Locator::Get().ShaderService("./Resources/DefaultPostprocessingShader.glsl");
		SetClearColor(0.0f, 0.0f, 0.0f);
		instance = this;
	}

	Game2D::~Game2D()
	{
		delete m_shaders["Default2DShader"];
		m_shaders.clear();

		for (auto& scene : m_scenes)
			delete scene;
		m_scenes.clear();

		delete resource;
		delete inputManager;
		delete eventManager;
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

			// Runs 60 times a second
			if (deltaTimeForSecond * fps > 1.0f)
			{
				deltaTimeForSecond = 0.0f;
				FixedUpdate();
			}

			// As fast as possible
			Update();

			// Sum up delta time to get total time difference
			deltaTimeForSecond += timer->DeltaTime();

			timer->Update();
			window->Update();
		}
	}

	void Game2D::SetClearColor(const Float & r, const Float & g, const Float & b)
	{
		glClearColor(r, g, b, 1.0f);
	}

	void Game2D::Tick()
	{
		Debug::Log(true);
		printf("\nFPS : %d", (Integer)(1.0f / timer->DeltaTime()));
	}

	void Game2D::FixedUpdate()
	{
		auto& objects(Locator::Get().GetAllObjects2D(m_scenes[m_activeScene]));
		for (auto* object : objects)
			object->FixedUpdate();
			
		//Collision2D::CollisionResolution(Locator::Get().GetAllObjects2D(m_scenes[m_activeScene]));
	}

	void Game2D::Update()
	{
		auto& objects(Locator::Get().GetAllObjects2D(m_scenes[m_activeScene]));
		for (auto* object : objects)
			object->Update();

		renderer->Initialize(*m_scenes[m_activeScene], m_shaders["Default2DShader"]);
		for (auto* object : objects)
		{
			if(GetBIT(object->GetFlags(), 0))
				renderer->Draw(*object, resource->GetSpriteSheet(object->material.diffuse));
		}
		renderer->Display(m_shaders["DefaultPostprocessingShader"], resource->GetSpriteSheet(objects[0]->material.diffuse));
		
		std::string event;
		while (eventManager->Receive(Events::SYSTEM, event))
		{
			if (event == "ShutDown") window->Close();
		}
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

	EventManager& Game2D::GetEventManager()
	{
		return *(instance->eventManager);
	}

	Resources& Game2D::GetResourceManager()
	{
		return *(instance->resource);
	}

	void Game2D::ActivateScene(const PDUInteger& id)
	{
		instance->m_activeScene = id;
	}

	void Game2D::ActivateNextScene()
	{
		instance->m_activeScene++;
	}

	PDUInteger Game2D::PushScene(Scene* scene)
	{
		instance->m_scenes.push_back(scene);
		return instance->m_scenes.size() - 1;
	}

	void Game2D::PopSceneBack()
	{
		delete (instance->m_scenes.back());
		instance->m_scenes.pop_back();
	}

	void Game2D::PopSceneFront()
	{
		delete (instance->m_scenes.front());
		instance->m_scenes.pop_front();
	}

	Scene& Game2D::GetCurrentScene()
	{
		return *instance->m_scenes[instance->m_activeScene];
	}

	void Game2D::AddGameObject2D(GameObject2D* object2D, const Character* name)
	{
		instance->m_scenes[instance->m_activeScene]->AddObject2D(object2D, name);
	}

	GameObject2D& Game2D::GetObject2D(const Character* name)
	{
		return instance->m_scenes[instance->m_activeScene]->GetObject2D(name);
	}

	void Game2D::RemoveObject2D(const Character* name)
	{
		instance->m_scenes[instance->m_activeScene]->RemoveObject2D(name);
	}

	const Float Game2D::fps = 60.0f;

	Game2D* Game2D::instance = nullptr;

}