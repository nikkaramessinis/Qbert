#include "QBERT.h"

void QBERT::setCubeX(int x)
{
	cubeX = x;
}

void QBERT::setCubeY(int y)
{
	cubeY = y;
}

int QBERT::getCubeX(void)
{
	return cubeX;
}

int QBERT::getCubeY(void)
{
	return cubeY;
}

void QBERT::Display(void)
{
	QbertSprite->Display();
}
int QBERT::getLife() {
	return life;
}
void QBERT::setLife(int lives)
{
	if(lives>=0)
	life = lives;
}
Sprite* QBERT::GetSprite() {
	return QbertSprite;
}

QBERT::QBERT(Point * p, AnimationFilm * film)
{
	QbertSprite = new Sprite(p->x, p->y, film);
	QbertSprite->SetVisibility(true);
	QbertSprite->SetFrame(0);
	life = 2;

	cubeX = 1;
	cubeY = 1;
	
	qbertLastX = 1;
	qbertLastY = 1;
}

void setPoint(int x,int y) {



}

QBERT::~QBERT()
{

}
