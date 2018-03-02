#include "MovingPathAnimator.h"
#include "AnimatorHolder.h"


extern int eventFlag;

void MovingPathAnimator::Progress(timestamp_t currTime)
{
	if (currTime > lastTime && currTime - lastTime >= anim->GetCurrentDelay()) {
		if (((int)anim->GetFrame()) <=((int)sprite->GetFilm()->GetTotalFrames())) {
			sprite->SetFrame(anim->GetFrame());
			sprite->Move(anim->GetCurrentDx(), anim->GetCurrentDy());
		
			anim->NextPos();
			if (anim->GetPos() >= anim->GetMaxPos())
			{
				state = ANIMATOR_FINISHED;
				NotifyStopped();
				anim->SetPos(0); 
			}
			else
			{
				lastTime += anim->GetCurrentDelay();
				Progress(currTime);
			}
		}
	}

}

void MovingPathAnimator::Start(Sprite * s, MovingPathAnimation * a, timestamp_t t)
{
	sprite = s;
	anim = a;
	anim->SetPos(0);
	lastTime = t;
	state = ANIMATOR_RUNNING;
}


MovingPathAnimator::MovingPathAnimator()
	:sprite((Sprite*)0), anim((MovingPathAnimation*)0) {
}

MovingPathAnimator::~MovingPathAnimator()
{
}
