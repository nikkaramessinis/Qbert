#include "DestructionManager.h"

list<LatelyDestroyable*> DestructionManager::dead;

void DestructionManager::Register(LatelyDestroyable* o)
{
	assert(!o->IsAlive());
	dead.push_back(o);
}

void DestructionManager::Commit()
{
	for_each(dead.begin(), dead.end(), LatelyDestroyable::Delete());
	dead.clear();
}
