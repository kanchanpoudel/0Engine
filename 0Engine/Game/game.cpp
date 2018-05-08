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
		timer = new Timer;
		OnConstruction();
	}

	void Game2D::Start()
	{
		window->Show();
		//TO-DO
		while (window->IsRunning())
		{
			window->Update();
		}
		delete window;
		delete timer;
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