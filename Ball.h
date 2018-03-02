#pragma once
#include "Sprite.h"
#include "Rect.h"
#include "MovingPathAnimator.h"
#include "Animation.h"
#include "AnimatorHolder.h"


class Ball
{
private:
	Sprite * BallSprite;
	MovingPathAnimator * BallAnimator;
	MovingPathAnimation * LBallAnimation,*RBallAnimation;
	
	long double timeAlive;
	long double timeFromLastMove;


public:
	bool isAlive = false;
	int ballTotalMoves;
	int movesFromLastSpawn;
	long double ballBornAt = 0;

	bool canSpawn = true;

	void Display(void);
	Sprite * GetSprite();

	long double getTimeFromLastMove();
	void resetTimeFromLastMove();
	void incrementTimeFromLastMove(long double);
	void Fall(void);

	void fallRight(timestamp_t timestamp);
	void fallLeft(timestamp_t timestamp);

	MovingPathAnimation* getRAnimation(){ return RBallAnimation; }
	MovingPathAnimation* getLAnimation() { return LBallAnimation; }
	MovingPathAnimator* getAnimator() { return BallAnimator; }
	Ball(Point * p, AnimationFilm *film,MovingPathAnimator * animator,MovingPathAnimation * Lanimation, MovingPathAnimation * Ranimation);
	~Ball();
};

