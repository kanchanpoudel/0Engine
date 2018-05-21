#include "our_game.h"

int main()
{
	s00nyaApp* game = new s00nyaApp;
	game->Start();
	delete game;
	return 0;
}