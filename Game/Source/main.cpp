#include "s00nya.h"
#include <iostream>

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
		if (input->Pressed(Keys::ESCAPE))
			window->Close();
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