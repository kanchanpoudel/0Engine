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
		delete window;
	}

	void Lie::Construct(const char* title, const int& width, const int& height)
	{
		window = new Window(title, width, height);
	}

	void Lie::Start()
	{
		//TO-DO
		while (window->IsRunning())
		{
			window->Update();
		}
	}

	void Lie::Tick()
	{
		//TO-DO
	}

	void Lie::FixedUpdate()
	{
	}

	void Lie::Update()
	{
	}

}