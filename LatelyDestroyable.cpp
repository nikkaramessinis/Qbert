#include "LatelyDestroyable.h"

bool LatelyDestroyable::IsAlive() const
{
	return alive;
}

void LatelyDestroyable::Destroy()
{
	if (alive)
	{
		alive = false;
		DestructionManager::Register(this);
	}
}

void LatelyDestroyable::Delete::operator()(LatelyDestroyable* o) const
{
	o->inDestruction = true;
	delete o;
}

LatelyDestroyable::LatelyDestroyable() : alive(true), inDestruction(false) {}

LatelyDestroyable::~LatelyDestroyable()
{
	assert(inDestruction);
}

