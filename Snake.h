#pragma once
#include "Sprite.h"
#include "Rect.h"
#include "MovingPathAnimator.h"
#include "Animation.h"
#include "AnimatorHolder.h"

extern MovingPathAnimation* SnakeFallLeft;
extern MovingPathAnimation* SnakeFallRight;
class Snake
{
private:
	

	

	MovingPathAnimator * SnakeAnimator;
	MovingPathAnimation * SnakeLeft;
	MovingPathAnimation * SnakeRight;
	MovingPathAnimation *SnakeDown;
	MovingPathAnimation *SnakeUp;
	long double timeAlive;
	long double timeFromLastMove;
	int cubeX;
	int cubeY;
	int totalMoves;

public:

	Sprite * SnakeSprite;
	Sprite * ballSnakeSprite;
	Sprite *snakeBodySprite;


	void setSprite(Sprite* sprite);

	long double snakeBornAt;
	int movesAsBall = 0;
	
	void setTotalMoves(int x);
	int getTotalMoves(void);

	void setCubeX(int x);
	void setCubeY(int y);

	int getCubeX(void);
	int getCubeY(void);

	void moveUp(timestamp_t timestamp);
	void moveDown(timestamp_t timestamp);
	void moveRight(timestamp_t timestamp);
	void moveLeft(timestamp_t timestamp);
	void fallLeft(timestamp_t timestamp);
	void fallRight(timestamp_t timestamp);
	void Display(void);
	Sprite * GetSprite();
	long double getTimeFromLastMove();
	void resetTimeFromLastMove();


	void ChangeSprite(AnimationFilm *film) {
		size_t x=SnakeSprite->getX1();
		size_t y = SnakeSprite->getY1();

		//SnakeSprite = new Sprite(x, y, film);
		//memory leakkkk
		//collisionManager->addBot(SnakeSprite);
		
	}


	void changeToBall() {
		size_t x = SnakeSprite->getX1();
		size_t y = SnakeSprite->getY1();

		SnakeSprite = ballSnakeSprite;
		SnakeSprite->setX1(x);
		SnakeSprite->setY1(y);
	}
	void changeToSnake() {
		size_t x = SnakeSprite->getX1();
		size_t y = SnakeSprite->getY1();

		SnakeSprite = snakeBodySprite;
		SnakeSprite->setX1(x);
		SnakeSprite->setY1(y);

	}

	void ChangeAnimation(MovingPathAnimation* _SnakeLeft, MovingPathAnimation* _SnakeRight)
	{
		SnakeDown = _SnakeLeft;
		SnakeRight = _SnakeRight;
	}



	Snake(Point * p, AnimationFilm *film, MovingPathAnimator* _SnakeAnimator, MovingPathAnimation* _SnakeLeft, MovingPathAnimation* _SnakeRight, MovingPathAnimation * _SnakeDown, MovingPathAnimation* _SnakeUp) {
		SnakeSprite = new Sprite(p->x, p->y, film);
		SnakeSprite->SetVisibility(false);
		SnakeSprite->SetFrame(0);
		cubeX = 2;
		cubeY = 2;
		totalMoves = 0;
		SnakeAnimator = _SnakeAnimator;
		SnakeDown = _SnakeDown;
		SnakeLeft = _SnakeLeft;
		SnakeRight = _SnakeRight;
		SnakeUp = _SnakeUp;

		SnakeSprite->setX1(1);
		SnakeSprite->setY1(1);

	}

	~Snake();
};

