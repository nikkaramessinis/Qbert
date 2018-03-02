#pragma once
#include "Sprite.h"
#include "Rect.h"

class QBERT
{
private:
	int life;
	Sprite * QbertSprite;

	int cubeX;
	int cubeY;


	

public:

	bool collisionSensitive = true;


	int qbertLastX;
	int qbertLastY;

	void setCubeX(int x);
	void setCubeY(int y);

	int getCubeX(void);
	int getCubeY(void);

	void Display(void);
	int getLife();
	void setLife(int lives);
	Sprite * GetSprite();
	QBERT(Point * p , AnimationFilm *film);
	~QBERT();
};

