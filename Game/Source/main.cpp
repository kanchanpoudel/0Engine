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
		if (Input::Pressed(Keys::ESCAPE))
			window->Close();

		if (Input::Pressed(Buttons::MOUSE_LEFT_CLICK))
			printf("\n%f %f", Input::CursorPositionX(), Input::CursorPositionY());
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