#include "lie.h"

using namespace Lie;

class ExampleGame : public Lie
{
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