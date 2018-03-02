#pragma once
#include "Animator.h"
#include "Sprite.h"
#include "MovingAnimation.h"
class MovingAnimator :public Animator
{

	Sprite* sprite;
	MovingAnimation* anim;

public:
	void Progress(timestamp_t currTime);
	void Start(Sprite* s, MovingAnimation* a, timestamp_t t);
	MovingAnimator(void);
	~MovingAnimator();
};

