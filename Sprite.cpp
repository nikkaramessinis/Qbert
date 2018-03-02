#include "Sprite.h"


void Sprite::SetFrame(int i)
{
	if (i != frameNo) {
		assert(i < currFilm->GetTotalFrames());
		frameNo = i;
		frameBox = currFilm->GetFrameBox(frameNo);

		//rasi ananewsh x2 yw analoga me to neo frame
		x2 = x + frameBox.getWidth();
		y2 = y + frameBox.getHeight();

	}

}



int Sprite::GetFrame(void) const
{
	return frameNo;
}


AnimationFilm* Sprite::GetFilm()
{
	return currFilm;
}

void Sprite::SetVisibility(bool v)
{
	isVisible = v;
}

bool Sprite::IsVisible(void) const
{
	return isVisible;
}

bool Sprite::CollisionCheck(Sprite * s)
{
	return false;
}

Sprite::Sprite(float _x, float _y, AnimationFilm *film) :x(_x), y(_y), currFilm(film), isVisible(true)
{
	frameNo = currFilm->GetTotalFrames();
	SetFrame(0);

	// initialize kai x2 y2 analoga me to height kai width tou current frame
	x2 = x + frameBox.getWidth();
	y2 = y + frameBox.getHeight();

	//this->printCoordinates();
}

void Sprite::setX1(float x1) {
	x = x1;
	x2 = x + frameBox.getWidth();
}
void Sprite::setY1(float y1) {
	y = y1;
	y2 = y + frameBox.getHeight();
}
//void setX2(float x2);

//void setY2(float y2);

void Sprite::printCoordinates() {
	cout << endl << "x " << x << endl;
	cout << "y " << y << endl;
	cout << "x2 " << x2 << endl;
	cout << "y2 " << y2 << endl;
	cout << endl;
}

//TODO
void Sprite::Move(int dx, int dy) {
	x += dx;
	y += dy;
	//rasi ananewsh twn sintetagmenwn katw deksia gwnia
	x2 += dx;
	y2 += dy;

	//this->printCoordinates();

}


void Sprite::Display(void) {
	if (IsVisible())
		currFilm->DisplayFrame(currFilm->GetBitmap(), Point(x, y), frameNo);
}


float Sprite::getX1() {
	return x;
}

float Sprite::getX2() {
	return x2;
}
float Sprite::getY1() {
	return y;
}
float Sprite::getY2() {
	return y2;
}

float Sprite::getCenterX()
{
	return (x + x2) / 2;
}

float Sprite::getCenterY()
{
	return (y + y2) / 2;
}



Sprite::~Sprite()
{
}
