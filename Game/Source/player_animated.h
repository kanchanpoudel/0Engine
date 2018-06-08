#pragma once
#include "s00nya.h"
#include <iostream>

using namespace s00nya;

class PlayerAnimated : public GameObject2D
{

public:
	Input& input;
	Timer& timer;
	Float speed = 200.0f;
	Float lastTime = 0.0f;

	PlayerAnimated() :
		GameObject2D(
			Transform2D({ 200.0f, 200.0f, 0.0f }, { 1.0f, 1.0f }, 0.0f), 
			Dimension(50.0f, 80.0f),
			Material()),
		input(Game2D::GetInput()),
		timer(Game2D::GetTimer())
	{
		this->material.frame = 0;
		this->material.diffuse = "Player";
		this->material.type = Material::Type::CLAMP_TO_EDGE;
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
			transform.position.x -= (timer.DeltaTime()*speed);
	
		if (input.Held(Keys::DIRECTIONAL_RIGHT))
			transform.position.x += (timer.DeltaTime()*speed);
		
		if (input.Held(Keys::DIRECTIONAL_UP))
			transform.position.y += (timer.DeltaTime()*speed);
		
		if (input.Held(Keys::DIRECTIONAL_DOWN))
			transform.position.y -= (timer.DeltaTime()*speed);
		
		if (input.Pressed(Keys::ESCAPE))
			Game2D::GetEventManager().Push(Events::SYSTEM, "ShutDown");
	}

};