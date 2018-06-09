#include "s00nya.h"
#include "player_animated.h"
#include "player.h"

using namespace s00nya;

// Derivation from the Game2D class
class MyGame : public Game2D
{
private:
	PDUInteger level1; // Store Scene ID

public:
	MyGame() :
		// Constructing application with title "Example Game" of window size 800 X 600 and enable double sampling
		Game2D("Example Game", 800, 600, Samples::SAMPLE_DOUBLE)
	{
		// Clears the screen with black color
		SetClearColor(0.0f, 0.0f, 0.0f);

		// Load game resources
		resource->LoadRawImage("./Resources/window_test_icon.png", "WolfIcon");
		resource->LoadSpriteSheet("./Resources/player.png", 4, 4, "Player");

		// Set the window icon from the loaded RawImage
		window->SetIcon(resource->GetRawImage("WolfIcon"));

		// Create a new Scene with orthographic camera
		level1 = PushScene(new Scene({ -1.0f, 1.0f }, { 0.0f, 800.0f }, { 600.0f, 0.0f }));
		ActivateScene(level1);

		// Add Objects to the currently active scene
		AddGameObject2D(new PlayerAnimated(), "Hero");
		AddGameObject2D(new Player(), "Another");
	}

};

int main()
{
	MyGame* game = new MyGame; 	// Construct game class
	game->Start();				// Game loop
	delete game;

	//system("pause");
	return 0;
}