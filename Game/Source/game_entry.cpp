#include "s00nya.h"
#include "player_animated.h"
#include "player.h"

using namespace s00nya;

// Derivation from the Game2D class, contains only definition
class MyGame : public Game2D
{
private:
	PDUInteger level1;
public:
	MyGame() :
		Game2D("Example Game", 800, 600, Samples::SAMPLE_DOUBLE)
	{
		SetClearColor(0.0f, 0.0f, 0.0f);

		resource->LoadRawImage("./Resources/window_test_icon.png", "WolfIcon");
		window->SetIcon(resource->GetRawImage("WolfIcon"));

		resource->LoadSpriteSheet("./Resources/player.png", 4, 4, "Player");

		level1 = PushScene(new Scene({ -1.0f, 1.0f }, { 0.0f, 800.0f }, { 600.0f, 0.0f }));
		ActivateScene(level1);

		AddGameObject2D(new PlayerAnimated(), "Hero");
		AddGameObject2D(new Player(), "Another");
	}

};

int main()
{
	MyGame* game = new MyGame;
	game->Start();
	delete game;

	//system("pause");
	return 0;
}