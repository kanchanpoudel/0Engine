#include "Game/game.h"
#include "Graphics/window.h"
#include "Debugger/logger.h"
#include "Game/timer.h"
#include "Input/input.h"

namespace s00nya
{

	Game2D::Game2D() :
		window(nullptr), timer(nullptr), input(nullptr)
	{
	}

	Game2D::~Game2D()
	{
	}

	void Game2D::Construct(const char* title, const int& width, const int& height)
	{
		Debug::Initialize();
		window = new Window(title, width, height);
		timer = new Timer();
		input = window->GetInputSystem();
		OnConstruction();
	}

	void Game2D::Start()
	{
		window->Show();

		// Time Management
		float now = Timer::ElaspedTime();
		float deltaTimeForSecond = 0.0f;
		
		while (window->IsRunning())
		{
			// Runs every 1 second
			if (Timer::ElaspedTime() - now > 1.0f)
			{
				now = Timer::ElaspedTime();
				Debug::Log(true, true);
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

		delete input;
		delete timer;
		delete window;
		Debug::ShutDown();
	}

	void Game2D::Tick()
	{
		printf("\nFPS : %d", (int)(1.0f / timer->DeltaTime()));
	}

	void Game2D::OnConstruction()
	{
	}

	void Game2D::FixedUpdate()
	{
	}

	void Game2D::Update()
	{
	}

	const float Game2D::fps = 60.0f;

}