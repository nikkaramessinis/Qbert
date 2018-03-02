#include "Rect.h"
#include<iostream>
using namespace std;


//default constructor rasi
Rect::Rect()
	:x(0), y(0), w(0), h(0) {}

Rect::Rect(float _x, float _y, float _w, float _h)
	:x(_x),y(_y),w(_w),h(_h){}


Rect::~Rect()
{
}



float Rect::getX(void) { return x; }
float Rect::getY(void) { return y; }
float Rect::getWidth(void) { return w; }
float Rect::getHeight(void) { return h; }


void Rect::setX(float x) { this->x = x; }
void Rect::setY(float y) { this->y = y; }
void Rect::setWidth(float w) { this->w = w; }
void Rect::setHeight(float h) { this->h = h; }

void Rect::toString(void) { cout << x << endl << y << endl << w << endl << h; }

Point::Point()
	:x(0), y(0) {}

Point::Point(float _x, float _y)
	: x(_x), y(_y) {}
