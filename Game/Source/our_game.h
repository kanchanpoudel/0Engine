#pragma once
#include "s00nya.h"
//
// Application Declarations and entry point
//

using namespace s00nya;

// Derivation from the Game2D class, contains only definition
class s00nyaApp : public Game2D
{
private:
	PDUInteger level1;
public:
	s00nyaApp();
};