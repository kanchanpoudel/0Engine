#include "our_game.h"
#include <iostream>

using namespace s00nya;

s00nyaApp::s00nyaApp():
	Game2D("Example Game", 800, 600)
{
	inputManager->AddKeyMap("Jump", { Keys::SPACE, Keys::ALPAHBET_W });
	inputManager->AddKeyMap("Quit", { Keys::ESCAPE, Keys::ALPAHBET_Q });
}

void s00nyaApp::FixedUpdate()
{

}

void s00nyaApp::Update()
{
	if (inputManager->KeyMapHeld("Jump"))
		std::cout << "Player Jumped!" << std::endl;
	if (inputManager->KeyMapPressed("Quit"))
		window->Close();
}