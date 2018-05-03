#include "s00nya.h"

using namespace s00nya;

class ExampleGame : public Game2D
{
	void OnConstruction() override
	{

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