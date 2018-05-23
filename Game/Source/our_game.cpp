#include "our_game.h"
#include <iostream>

using namespace s00nya;

s00nyaApp::s00nyaApp() :
	Game2D("Example Game", 800, 600)
{
	resource->LoadRawImage("./Resources/window_test_icon.png", "WolfIcon");
	resource->LoadRawImage("./Resources/cursor_grey_light.png", "GreyLightCursor");
	window->SetIcon(resource->GetRawImage("WolfIcon"));
	window->ChangeCursor(resource->GetRawImage("GreyLightCursor"));
}