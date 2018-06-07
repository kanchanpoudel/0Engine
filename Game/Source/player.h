#pragma once
#include "s00nya.h"
#include <iostream>

using namespace s00nya;

class Player : public GameObject2D
{

public:
	Input& input;
	Timer& timer;
	Float speed = 200.0f;
	Float lastTime = 0.0f;

	Player(const Transform2D& trans, const Dimension& dim, const Material& mat) :
		GameObject2D(trans, dim, mat), input(Game2D::GetInput()), timer(Game2D::GetTimer())
	{
	}

	Player(const Transform2D& trans, const Dimension& dim, const Material& mat, const Collider2D& col) :
		GameObject2D(trans, dim, mat, col), input(Game2D::GetInput()), timer(Game2D::GetTimer())
	{
	}

	void FixedUpdate() override
	{
		if ((timer.ElaspedTime() - lastTime) > 1.0f)
		{
			lastTime = timer.ElaspedTime();
			this->material.frame++;
			if (this->material.frame > 15) material.frame = 0;
		}
	}

	void Update() override
	{
		if(input.Held(Keys::DIRECTIONAL_LEFT))
		{
			transform.position.x -= (timer.DeltaTime()*speed);
		}
		if (input.Held(Keys::DIRECTIONAL_RIGHT))
		{
			transform.position.x += (timer.DeltaTime()*speed);
		}
		if (input.Held(Keys::DIRECTIONAL_UP))
		{
			transform.position.y += (timer.DeltaTime()*speed);
		}
		if (input.Held(Keys::DIRECTIONAL_DOWN))
		{
			transform.position.y -= (timer.DeltaTime()*speed);
		}
		if (input.Pressed(Keys::ESCAPE))
			Game2D::GetEventManager().Push(Events::SYSTEM, "ShutDown");
	}

};