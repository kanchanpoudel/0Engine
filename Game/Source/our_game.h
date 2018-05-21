#pragma once
#include "s00nya.h"
//
// Application Declarations and entry point
//

// Derivation from the Game2D class, contains only definition
class s00nyaApp : public s00nya::Game2D
{
public:
	s00nyaApp();

	void FixedUpdate() override;

	void Update() override;
};