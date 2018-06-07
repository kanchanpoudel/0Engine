#include "s00nya.h"
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
		SetClearColor(0.0f, 0.0f, 0.01f);

		resource->LoadRawImage("./Resources/window_test_icon.png", "WolfIcon");
		window->SetIcon(resource->GetRawImage("WolfIcon"));

		resource->LoadSpriteSheet("./Resources/player.png", 4, 4, "Player");

		Dimension dimension(220.0f, 280.0f);
		Collider2D col;

		Transform2D playerTrans;
		playerTrans.position = { 200.0f, 200.0f, 0.0f };
		playerTrans.rotation = 0.0f;
		playerTrans.scale = { 0.25f, 0.25f };

		Transform2D another;
		another.position = { 0.0f, 0.0f, 0.0f };
		another.rotation = 0.0f;
		another.scale = { 0.25f, 0.25f };

		Material playerMat;
		playerMat.diffuse = "Player";
		playerMat.frame = 0;
		playerMat.type = Material::Type::CLAMP_TO_EDGE;

		level1 = PushScene(new Scene({ -1.0f, 1.0f }, { 0.0f, 800.0f }, { 600.0f, 0.0f }));
		ActivateScene(level1);

		AddGameObject2D(new Player(playerTrans, dimension, playerMat, col), "Hero");
		AddGameObject2D(new GameObject2D(another, dimension, playerMat, col), "Another");
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