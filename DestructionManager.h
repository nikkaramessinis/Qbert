#ifndef DESTRUCTIONMANAGER_H
#define DESTRUCTIONMANAGER_H

#include "LatelyDestroyable.h"
#include <algorithm>
#include <list>


class LatelyDestroyable;

class DestructionManager
{
	static std::list<LatelyDestroyable*> dead;

public:
	static void Register(LatelyDestroyable* o);
	static void Commit();
};
#endif

