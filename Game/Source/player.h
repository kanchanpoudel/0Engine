#pragma once
#include "our_game.h"
#include <iostream>

using namespace s00nya;

class Player : public GameObject2D
{

public:
	Float speed = 200.0f;

	Player(const Transform2D& trans, const Material& mat) :
		GameObject2D(trans, mat)
	{
	}

	void Update()
	{
		if(s00nyaApp::GetInput().Held(Keys::DIRECTIONAL_LEFT))
		{
			transform.position.x -= (s00nyaApp::GetTimer().DeltaTime()*speed);
		}
		if (s00nyaApp::GetInput().Held(Keys::DIRECTIONAL_RIGHT))
		{
			transform.position.x += (s00nyaApp::GetTimer().DeltaTime()*speed);
		}
		if (s00nyaApp::GetInput().Held(Keys::DIRECTIONAL_UP))
		{
			transform.position.y += (s00nyaApp::GetTimer().DeltaTime()*speed);
		}
		if (s00nyaApp::GetInput().Held(Keys::DIRECTIONAL_DOWN))
		{
			transform.position.y -= (s00nyaApp::GetTimer().DeltaTime()*speed);
		}
	}

};