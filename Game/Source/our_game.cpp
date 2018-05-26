#include "our_game.h"
#include "player.h"
#include <iostream>

using namespace s00nya;

s00nyaApp::s00nyaApp() :
	Game2D("Example Game", 800, 600)
{
	resource->LoadRawImage("./Resources/window_test_icon.png", "WolfIcon");
	window->SetIcon(resource->GetRawImage("WolfIcon"));

	resource->LoadSpriteSheet("./Resources/player.png", 4, 4, "Player");

	Dimension dimension({ 0.0f, 0.0f }, 200.0f, 200.0f);
	Collider2D col(50.0f, 50.0f);

	Transform2D playerTrans;
	playerTrans.position = { 200.0f, 200.0f, 0.0f };
	playerTrans.rotation = 0.0f;
	playerTrans.scale = { 0.5f, 0.5f };

	Transform2D another;
	another.position = { 0.0f, 0.0f, 0.0f };
	another.rotation = 0.0f;
	another.scale = { 0.5f, 0.5f };

	Material playerMat;
	playerMat.diffuse = "Player";
	playerMat.frame = 0;
	playerMat.type = Material::Type::CLAMP_TO_EDGE;

	level1 = PushScene(new Scene({ -1.0f, 1.0f }, { 0.0f, 800.0f }, { 600.0f, 0.0f }));
	ActivateScene(level1);

	AddGameObject2D(new Player(playerTrans, dimension, playerMat, col), "Hero");
	AddGameObject2D(new GameObject2D(another, dimension, playerMat, col), "Another");
}