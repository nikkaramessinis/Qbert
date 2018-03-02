
#pragma once
#include <list>
#include <algorithm>
#include <time.h>
#include <iostream>
#include "Animator.h"
extern int eventFlag;
using namespace std;

class AnimatorHolder
{
private:
	static list<Animator*> running, suspended;
	static AnimatorHolder * holder;
	AnimatorHolder();
	class ProgressFunctor : public unary_function<Animator*, void>
	{
		timestamp_t t;
		public:
			void operator()(Animator* a) const
			{
				a->Progress(t);
			}
			ProgressFunctor(timestamp_t _t) : t(_t) {}
	};
public:
	static void Register(Animator* a);
	static void Cancel(Animator* a);
	static void MarkAsRunning(Animator* a);
	static void MarkAsSuspended(Animator* a);
	static void Progress(timestamp_t currTime);
	static void check();

	static AnimatorHolder& Get();
	~AnimatorHolder();
};
