#include "GameObject\gameobject.h"

namespace s00nya {

	Gameobject::Gameobject() :
		position(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f), rotation(0.0f)
	{
	}

	Gameobject::Gameobject(Vector3 pos,Vector3 sc,float rot=0.0f) :
		position(pos), scale(sc), rotation(rot)
	{
	}
}