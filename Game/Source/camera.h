#pragma once
#include "s00nya.h"

using namespace s00nya;

class MainCamera : public Camera
{

public:
	Input& input;				// Requires Input component
	Timer& timer;				// Requires Timer component
	Float speed = 200.0f;		// Movement speed

	MainCamera() :
		Camera(
			Transform2D({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 0.0f }, 0.0f),
			{ 0.0f, 600.0f, 800.0f, 0.0f }
		),
		input(Game2D::GetInput()),
		timer(Game2D::GetTimer())
	{
	}

	void Update() override
	{
		// Control Game Object using I, J, K, L keys

		if (input.Held(Keys::KEY_J))
			transform.position.x -= (timer.DeltaTime()*speed);

		if (input.Held(Keys::KEY_L))
			transform.position.x += (timer.DeltaTime()*speed);

		if (input.Held(Keys::KEY_I))
			transform.position.y += (timer.DeltaTime()*speed);

		if (input.Held(Keys::KEY_K))
			transform.position.y -= (timer.DeltaTime()*speed);
	}

};