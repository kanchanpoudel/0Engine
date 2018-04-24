#include "lie.h"

using namespace Lie;

class ExampleGame : public Lie
{
	void OnConstruction() override
	{
		//window->ToggleFullscreen();
		window->Resize(500, 500);
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
	game->Construct("Example Game", 800, 600);
	game->Start();
	delete game;
	return 0;
}