#include "AnimatorHolder.h"


AnimatorHolder  *  AnimatorHolder::holder = 0;

list<Animator*> AnimatorHolder::running, AnimatorHolder::suspended;

AnimatorHolder::AnimatorHolder()
{
}

void AnimatorHolder::Register(Animator * a)
{
	suspended.push_back(a);
}

void AnimatorHolder::Cancel(Animator * a)
{
	suspended.remove(a);
}

void AnimatorHolder::MarkAsRunning(Animator * a)
{
	suspended.remove(a);
	running.push_back(a);
}

void AnimatorHolder::MarkAsSuspended(Animator * a)
{
	running.remove(a);
	suspended.push_back(a);
}

void AnimatorHolder::Progress(timestamp_t currTime)
{
	std::for_each(
		
		running.begin(), running.end(), ProgressFunctor(currTime)
	);

}

void AnimatorHolder::check()
{
	for (list<Animator*>::iterator it = running.begin(); it != running.end(); ++it)
	if((*it)->getState()== ANIMATOR_FINISHED){
		AnimatorHolder::Get().MarkAsSuspended(*it);
		eventFlag = 0;
	}
}

AnimatorHolder & AnimatorHolder::Get()
{
	if (holder == NULL)
		holder = new AnimatorHolder();
	return *holder;
}

AnimatorHolder::~AnimatorHolder()
{
	running.clear();
	suspended.clear();
}



