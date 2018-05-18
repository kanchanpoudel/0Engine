#include "s00nya.h"
#include <iostream>

using namespace s00nya;

class ExampleGame : public Game2D
{	

	InputManager inputManager;

	void OnConstruction() override
	{
		inputManager.SupplySystem(input);
		inputManager.AddKeyMap("Jump", { Keys::SPACE, Keys::ALPAHBET_W });
		inputManager.AddKeyMap("Quit", { Keys::ESCAPE, Keys::ALPAHBET_Q });
	}

	void FixedUpdate() override
	{
		
	}

	void Update() override
	{
		if(inputManager.KeyMapHeld("Jump"))
			std::cout << "Player Jumped!" << std::endl;
		if (inputManager.KeyMapPressed("Quit"))
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