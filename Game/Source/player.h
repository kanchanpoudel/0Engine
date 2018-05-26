#pragma once
#include "our_game.h"
#include <iostream>

using namespace s00nya;

class Player : public GameObject2D
{

public:
	Float speed = 200.0f;
	Float lastTime = 0.0f;

	Player(const Transform2D& trans, const Dimension& dim, const Material& mat) :
		GameObject2D(trans, dim, mat)
	{
	}

	Player(const Transform2D& trans, const Dimension& dim, const Material& mat, const Collider2D& col) :
		GameObject2D(trans, dim, mat, col)
	{
	}

	void FixedUpdate() override
	{
		if ((s00nyaApp::GetTimer().ElaspedTime() - lastTime) > 1.0f)
		{
			lastTime = s00nyaApp::GetTimer().ElaspedTime();
			this->material.frame++;
			if (this->material.frame > 15) material.frame = 0;
		}
	}

	void Update() override
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
		if (s00nyaApp::GetInput().Pressed(Keys::ESCAPE))
			s00nyaApp::GetEventManager().Push(Events::SYSTEM, "ShutDown");
	}

};