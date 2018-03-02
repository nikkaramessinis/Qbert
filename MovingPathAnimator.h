#pragma once
#include "Animator.h"
#include "Sprite.h"
#include "MovingPathAnimation.h"
class MovingPathAnimator :public Animator
{
	Sprite* sprite;
	MovingPathAnimation* anim;
	
public:
	float x=32, y=48;
	void Progress(timestamp_t currTime);
	void Start(Sprite *s, MovingPathAnimation* a, timestamp_t);
	//start ena orisma
	//restart 
	//setanimation
	//clone
	//isdone

	MovingPathAnimator();
	~MovingPathAnimator();
};

