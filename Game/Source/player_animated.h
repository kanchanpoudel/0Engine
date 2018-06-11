#pragma once
#include "s00nya.h"
#include <iostream>

using namespace s00nya;

class PlayerAnimated : public GameObject2D
{

public:
	Input& input;					// Requires Input component
	Timer& timer;					// Requires Timer component
	Float speed = 200.0f;			// Movement speed
	Float lastTime = 0.0f;			// Time information for animation

	PlayerAnimated() :
		GameObject2D(
			Transform2D({ 200.0f, 200.0f, 0.0f }, { 1.0f, 1.0f }, { 50.0f, 80.0f }, 0.0f),
			Dimension(100.0f, 160.0f),
			Material(),
			Collider2D(Dimension(50.0f, 80.0f), "path_to_sat")
		),
		input(Game2D::GetInput()),
		timer(Game2D::GetTimer())
	{
		// Setting up Material properties
		this->material.frame = 0;
		this->material.diffuse = "Player";
		this->material.type = Material::Type::CLAMP_TO_EDGE;
	}

	void FixedUpdate() override
	{
		// Change the animation frame every second
		if ((timer.ElaspedTime() - lastTime) > 1.0f)
		{
			lastTime = timer.ElaspedTime();
			this->material.frame++;
			if (this->material.frame > 15) material.frame = 0;
		}
	}

	void Update() override
	{
		// Control game component using Directional keys

		if(input.Held(Keys::DIRECTIONAL_LEFT))
			transform.position.x -= (timer.DeltaTime()*speed);
	
		if (input.Held(Keys::DIRECTIONAL_RIGHT))
			transform.position.x += (timer.DeltaTime()*speed);
		
		if (input.Held(Keys::DIRECTIONAL_UP))
			transform.position.y += (timer.DeltaTime()*speed);
		
		if (input.Held(Keys::DIRECTIONAL_DOWN))
			transform.position.y -= (timer.DeltaTime()*speed);
		
		// If [ESCAPE] is pressed then Quit the Game
		if (input.Pressed(Keys::ESCAPE))
			Game2D::GetEventManager().Push(Events::SYSTEM, "ShutDown");
	}

};