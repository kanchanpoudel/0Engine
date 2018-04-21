#include "Game\game.h"
#include "Graphics\window.h"

namespace Lie
{

	Lie::Lie() :
		window{ nullptr }
	{
	}

	Lie::~Lie()
	{
	}

	void Lie::Construct(const char* title, const int& width, const int& height)
	{
		window = new Window(title, width, height);
		OnConstruction();
	}

	void Lie::Start()
	{
		window->Show();
		//TO-DO
		while (window->IsRunning())
		{
			window->Update();
		}
		delete window;
	}

	void Lie::Tick()
	{
		//TO-DO
	}

	void Lie::OnConstruction()
	{
	}

	void Lie::FixedUpdate()
	{
	}

	void Lie::Update()
	{
	}

}