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
#include "GameObject/camera.h"
#include "Graphics/renderer.h"
#include "Math/matrix3.h"
#include "GL/glew.h"

namespace s00nya
{

	Game2D::Game2D(const Character* title, const Integer& width, const Integer& height, const Samples& sample) :
		window(new Window(title, width, height)),
		timer(new Timer()),
		input(new Input(window->m_id)),
		inputManager(new InputManager(input)),
		eventManager(new EventManager()),
		resource(new Resources),
		renderer(new Renderer(
			window->Width() * (Integer)sample, 
			window->Height() * (Integer)sample, 
			window->Width(),
			window->Height()
		))
	{
		m_shaders["Default2DShader"] = Game2D::ParseShader("./Resources/Default2DShader.glsl");
		m_shaders["DefaultPostprocessingShader"] = Game2D::ParseShader("./Resources/DefaultPostprocessingShader.glsl");
		m_shaders["DefaultPostprocessingShader"]->Bind();
		m_shaders["DefaultPostprocessingShader"]->SetMatrix3("filterSlot0", Matrix3::EdgeDetection());
		m_shaders["DefaultPostprocessingShader"]->SetMatrix3("filterSlot1", Matrix3::BoxBlur());
		m_shaders["DefaultPostprocessingShader"]->SetMatrix3("filterSlot2", Matrix3::GaussianBlur());
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

	void Game2D::Run(Game2D* app)
	{
		app->window->Show();

		// Time Management
		Float now = Timer::ElaspedTime();
		Float deltaTimeForSecond = 0.0f;
		
		while (app->window->IsRunning())
		{
			// Get all the entities of the current scene
			auto& objects(Game2D::GetAllObjects2D(app->m_scenes[app->m_activeScene]));
			auto& cameras(Game2D::GetAllCameras(app->m_scenes[app->m_activeScene]));

			// Runs every 1 second
			if (Timer::ElaspedTime() - now > 1.0f)
			{
				now = Timer::ElaspedTime();
				app->Tick();
			}

			// Runs 60 times a second
			if (deltaTimeForSecond * fps > 1.0f)
			{
				deltaTimeForSecond = 0.0f;
				app->FixedUpdate(objects, cameras);
			}

			// As fast as possible
			app->Update(objects, cameras);

			// Sum up delta time to get total time difference
			deltaTimeForSecond += app->timer->DeltaTime();

			app->timer->Update();
			app->window->Update();
		}

		delete app;
	}

	void Game2D::Tick()
	{
		// Log to file
		Debug::Log(true);
		
		// Don't log to file
		//Debug::Log(false);

		// Display FPS to console window
		printf("\nFPS : %d", (Integer)(1.0f / timer->DeltaTime()));
	}

	void Game2D::FixedUpdate(std::vector<GameObject2D*>& objects, std::vector<Camera*>& cameras)
	{
		for (auto* object : objects)
			object->FixedUpdate();

		for (auto* camera : cameras)
			camera->FixedUpdate();
			
		// Commented out because not complete and doesn't work properly
		Collision2D::CollisionResolution(Game2D::GetAllObjects2D(m_scenes[m_activeScene]));
	}

	void Game2D::Update(std::vector<GameObject2D*>& objects, std::vector<Camera*>& cameras)
	{
		for (auto* object : objects)
			object->Update();

		for (auto* camera : cameras)
			camera->Update();

		// Render to frame
		renderer->Initialize(*m_scenes[m_activeScene], m_shaders["Default2DShader"]);
		for (auto* object : objects)
		{
			if(object->GetFlags() & RENDER_OBJECT)
				renderer->Draw(*object, resource->GetSpriteSheet(object->material.diffuse));
		}
		// Postprocess and render to display frame
		renderer->Display(m_shaders["DefaultPostprocessingShader"], resource->GetSpriteSheet(objects[0]->material.diffuse));
		
		// Check for all the events and resolve them
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

	void Game2D::AddCamera(Camera* camera, const Character* name)
	{
		instance->m_scenes[instance->m_activeScene]->AddCamera(camera, name);
	}

	Camera& Game2D::GetCamera(const Character* name)
	{
		return instance->m_scenes[instance->m_activeScene]->GetCamera(name);
	}

	void Game2D::RemoveCamera(const Character* name)
	{
		instance->m_scenes[instance->m_activeScene]->RemoveCamera(name);
	}

	const Float Game2D::fps = 60.0f;

	Game2D* Game2D::instance = nullptr;

	Shader* Game2D::ParseShader(const Character* path)
	{
		// Read all content from the file
		std::ifstream file(path, std::ios::in);
		std::stringstream stream;
		stream << file.rdbuf();
		file.close();
		std::string content(stream.str());

		/*
		* All shader code are expected in a single file
		* Three types of shaders are suppported : Vertex, Fragment and Geometry
		* Geometry shader is optional
		* Shader code must be in the order: Vertex, Geometry and Fragment with Goemetry being optional
		* Every shader must begin with a declaration of their respective type
		- `@Vertex Shader` : Vertex Shader
		- `@Fragment Shader` : Fragment Shader
		- `@Geometry Shader` : Geometry Shader
		*/

		// Extract codes for Vertex, Geometry (if available) and Fragment Shader
		PDUInteger vertexPos = content.find("@Vertex Shader");
		PDUInteger fragmentPos = content.find("@Fragment Shader");
		PDUInteger geometryPos = content.find("@Geometry Shader");
		// Given file content error / unsatisfied
		if (vertexPos == std::string::npos || fragmentPos == std::string::npos)
		{
			Debug::Add("Could not load Shader - " + std::string(path), Debug::S00NYA_LOG_WARNING);
			return nullptr;
		}

		// Return the Shader
		if (geometryPos == std::string::npos)
		{
			std::string vertex(content.substr(vertexPos + 14, fragmentPos - vertexPos - 14));
			std::string fragment(content.substr(fragmentPos + 16, content.length() - fragmentPos - 16));
			const Character* vertexCstr(vertex.c_str());
			const Character* fragmentCstr(fragment.c_str());
			return new Shader(vertexCstr, fragmentCstr);
		}
		else
		{
			std::string vertex(content.substr(vertexPos + 14, geometryPos - vertexPos - 14));
			std::string geometry(content.substr(geometryPos + 16, fragmentPos - geometryPos - 16));
			std::string fragment(content.substr(fragmentPos + 16, content.length() - fragmentPos - 16));
			const Character* vertexCstr(vertex.c_str());
			const Character* geometryCstr(geometry.c_str());
			const Character* fragmentCstr(fragment.c_str());
			return new Shader(vertexCstr, fragmentCstr, geometryCstr);
		}
	}

	std::vector<GameObject2D*>& Game2D::GetAllObjects2D(Scene* scene)
	{
		return scene->m_renderableObjects;
	}

	std::vector<Camera*>& Game2D::GetAllCameras(Scene* scene)
	{
		return scene->m_cameras;
	}

}