#include "Ball.h"
#include "Animator.h"
#include "SoundManager.h"

extern MovingPathAnimation* fallRightBall1;
extern MovingPathAnimation* fallRightBall2;
extern MovingPathAnimation* fallDownBall2;
extern MovingPathAnimation* fallDownBall1;


void Ball::Display(void) {
	BallSprite->Display();

}


Sprite * Ball::GetSprite() {
	return BallSprite;
}

Ball::Ball(Point * p, AnimationFilm *film,MovingPathAnimator * animator,MovingPathAnimation * Lanimation, MovingPathAnimation * Ranimation)
{
	BallSprite = new Sprite(p->x, p->y, film);
	BallSprite->SetVisibility(false);
	BallSprite->SetFrame(0);
	ballTotalMoves = 0;
	movesFromLastSpawn = 0;
	isAlive = false;
	RBallAnimation = Ranimation;
	LBallAnimation = Lanimation;
	BallAnimator = animator;
}

long double Ball::getTimeFromLastMove() {
	return timeFromLastMove;
}

void Ball::resetTimeFromLastMove() {
	timeFromLastMove = 0;
}

void Ball::incrementTimeFromLastMove(long double time) {
	timeFromLastMove += time;
}

void Ball::Fall(void)
{
}

void Ball::fallRight(timestamp_t timestamp)
{
	BallAnimator->Start(this->GetSprite(), fallRightBall1, timestamp);
	AnimatorHolder::Get().MarkAsRunning(BallAnimator);

	SoundManager::playBallJump();

}

void Ball::fallLeft(timestamp_t timestamp)
{
	BallAnimator->Start(this->GetSprite(), fallDownBall1, timestamp);
	AnimatorHolder::Get().MarkAsRunning(BallAnimator);

	SoundManager::playBallJump();

}

Ball::~Ball()
{
}
