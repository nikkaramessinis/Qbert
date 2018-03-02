#include "Animator.h"



void Animator::Stop()
{
	if (!HasFinished()) {
		state = ANIMATOR_STOPPED;
		NotifyStopped();
	
	}
}

animatorstate_t Animator::getState()
{
	return state;
}

void Animator::NotifyStopped(void) {
	if (onFinish)
		(*onFinish)(this, finishClosure);


}

//me thn timeshift kanoume pause to paixnidi arkei na kanoume meta timeshift animators
void Animator::TimeShift(timestamp_t offset) {
	lastTime += offset;

}

Animator::Animator(void) :
	lastTime(0), state(ANIMATOR_FINISHED), onFinish((FinishCallback)0), finishClosure((void*)0) {}

bool Animator::HasFinished(void) const
{
	return state != ANIMATOR_RUNNING;
}




void Animator::SetOnFinish(FinishCallback f, void * c)
{
	
		onFinish = f, finishClosure = c;
	
}




Animator::~Animator()
{
}


