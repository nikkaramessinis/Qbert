#ifndef LATELYDESTROYABLE_H
#define LATELYDESTROYABLE_H
#include <assert.h>
#include "DestructionManager.h"
#include <functional>
using namespace std;

class LatelyDestroyable {

	friend class DestructionManager;
	bool alive;
	bool inDestruction;
	virtual ~LatelyDestroyable();

	class Delete : public unary_function<LatelyDestroyable*, void>
	{
	public:
		void operator()(LatelyDestroyable* o) const;
	};
	friend class Delete;

public:
	bool IsAlive() const;
	void Destroy();
	LatelyDestroyable();
};
#endif