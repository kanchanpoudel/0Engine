#include "Game\game.h"
#include "Graphics\window.h"
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
		Timer::Initialize();
		OnConstruction();
	}

	void Game2D::Start()
	{
		window->Show();
		// Prasiddha and Shaswat have to correct the amount of loop called as required
		while (window->IsRunning())
		{
			window->Update();

			// Make this function be be called 60 times in a sec
			FixedUpdate(); 
			// Call this function as much as possible
			Update();
		}
		delete window;
	}

	void Game2D::Tick()
	{
		//TO-DO
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

}