
#include "Snake.h"
#include "SoundManager.h"
#include "Animator.h"



void Snake::setSprite(Sprite * sprite)
{
	SnakeSprite = sprite;
}

void Snake::setTotalMoves(int x)
{
	totalMoves = x;
}

int Snake::getTotalMoves(void)
{
	return totalMoves;
}

void Snake::setCubeX(int x)
{
	cubeX = x;
}

void Snake::setCubeY(int y)
{
	cubeY = y;
}

int Snake::getCubeX(void)
{
	return cubeX;
}

int Snake::getCubeY(void)
{
	return cubeY;
}

void Snake::moveUp(timestamp_t timestamp)
{
	//mikrenei to Y kai to x paramenei idio an to paratirisete etsi ginete


	cubeY--;


	SnakeAnimator->Start(this->GetSprite(), SnakeUp, timestamp);
	AnimatorHolder::Get().MarkAsRunning(SnakeAnimator);

	SoundManager::playSnakeJump();

}



void Snake::moveLeft(timestamp_t timestamp)
{

	cubeY--;
	cubeX--;

	SnakeAnimator->Start(this->GetSprite(), SnakeLeft, timestamp);
	AnimatorHolder::Get().MarkAsRunning(SnakeAnimator);

	SoundManager::playSnakeJump();
}

void Snake::fallLeft(timestamp_t timestamp)
{
	SnakeAnimator->Start(this->GetSprite(), SnakeFallRight, timestamp);
	AnimatorHolder::Get().MarkAsRunning(SnakeAnimator);

	SoundManager::playSnakeJump();
}

void Snake::fallRight(timestamp_t timestamp)
{
	SnakeAnimator->Start(this->GetSprite(), SnakeFallLeft, timestamp);
	AnimatorHolder::Get().MarkAsRunning(SnakeAnimator);

	SoundManager::playSnakeJump();
}


void Snake::moveDown(timestamp_t timestamp){


	//afksanete to Y kai to x paramenei idio an to paratirisete etsi ginete
	cubeY++;

	AnimatorHolder::Get().MarkAsSuspended(SnakeAnimator);
	SnakeAnimator->Start(this->GetSprite(), SnakeDown, timestamp);
	AnimatorHolder::Get().MarkAsRunning(SnakeAnimator);

	SoundManager::playSnakeJump();
}

void Snake::moveRight(timestamp_t timestamp){

	cubeY++;
	cubeX++;
	AnimatorHolder::Get().MarkAsSuspended(SnakeAnimator);
	SnakeAnimator->Start(this->GetSprite(), SnakeRight, timestamp);
	AnimatorHolder::Get().MarkAsRunning(SnakeAnimator);

	SoundManager::playSnakeJump();
}


void Snake::Display(void)
{
	SnakeSprite->Display();
}

Sprite* Snake::GetSprite() {
	return SnakeSprite;
}



long double Snake::getTimeFromLastMove() {
	return timeFromLastMove;
}

void Snake::resetTimeFromLastMove() {
	timeFromLastMove = 0;
}




Snake::~Snake()
{
}
