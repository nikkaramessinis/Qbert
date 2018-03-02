#include "MovingAnimator.h"



void MovingAnimator::Progress(timestamp_t currTime)
{
	if (currTime > lastTime && currTime - lastTime >= anim->GetDelay()) 
	{//TODO Sprite move
		//sprite->Move(anim->GetDx(), anim->GetDy());
		if (!anim->GetContinuous()) {
			state = ANIMATOR_FINISHED;
			NotifyStopped();
		}
		else {
			lastTime += anim->GetDelay();
			Progress(currTime);//Recursion make it a loop
		}
	}
}

void MovingAnimator::Start(Sprite * s, MovingAnimation * a, timestamp_t t)
{
	
		sprite = s;
		anim = a;
		lastTime = t;
		state = ANIMATOR_RUNNING;

	
}

MovingAnimator::MovingAnimator(void) :sprite((Sprite*)0), anim((MovingAnimation*)0)
{}




MovingAnimator::~MovingAnimator()
{}
