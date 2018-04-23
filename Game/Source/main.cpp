#include "lie.h"

using namespace Lie;

class ExampleGame : public Lie
{
	void OnConstruction() override
	{
		window->ToggleFullscreen();
	}

	void FixedUpdate() override
	{

	}

	void Update() override
	{

	}
};

int main()
{
	ExampleGame* game = new ExampleGame;
	game->Construct("Example Game", Window::WINDOW_AUTO_WIDTH, Window::WINDOW_AUTO_HEIGHT);
	game->Start();
	delete game;
	return 0;
}