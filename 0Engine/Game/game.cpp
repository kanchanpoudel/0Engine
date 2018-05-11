#include "Game\game.h"
#include "Graphics\window.h"
#include "Debugger\console_logger.h"
#include "Game\timer.h"

namespace s00nya
{

	Game2D::Game2D() :
		window(nullptr)
	{
	}

	Game2D::~Game2D()
	{
	}

	void Game2D::Construct(const char* title, const int& width, const int& height)
	{
		window = new Window(title, width, height);
		OnConstruction();
	}

	void Game2D::Start()
	{
		window->Show();

		// Time Management
		float now = Timer::ElaspedTime();
		float deltaTime = 0.0f;
		float timer = Timer::ElaspedTime();
		
		while (window->IsRunning())
		{
			// Runs every 1 second
			if (Timer::ElaspedTime() - timer > 1.0f)
			{
				timer = Timer::ElaspedTime();
				Tick();
			}
			
			// Runs 60 times a second
			if (deltaTime * fps > 1.0f)
			{
				deltaTime = 0.0f;
				FixedUpdate();
			}

			// Sum up delta time to get total time difference
			deltaTime += (Timer::ElaspedTime() - now);
			now = Timer::ElaspedTime();

			// As fast as possible
			Update();

			window->Update();
		}
		delete window;
	}

	void Game2D::Tick()
	{
		printf("\nFPS : %d", (int)(1.0f / Timer::DeltaTime()));
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