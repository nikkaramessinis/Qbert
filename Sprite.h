#include "Rect.h"
#include "AnimationFilm.h"
#include <iostream>
#include "Rect.h"
#include <allegro5\allegro.h>
#pragma once
class Sprite
{
	int frameNo;
	Rect frameBox;

	//panw aristerh gwnia
	float x;
	float y;
	//katw deksia gwnia
	float x2;
	float y2;


	bool isVisible;
	AnimationFilm *currFilm;
	//TileLayer myLayer; // TODO!!!!

public:
	//void setX();
	//void setY(int Y);

	float getX1();
	float getX2();
	float getY1();
	float getY2();

	float getCenterX();
	float getCenterY();


	void setX1(float x1);
	void setX2(float x2);
	void setY1(float y1);
	void setY2(float y2);

	void SetFrame(int i);
	int GetFrame(void) const;
	void SetVisibility(bool v);
	bool IsVisible(void) const;
	bool CollisionCheck(Sprite *s);
	AnimationFilm* GetFilm();

	Sprite(float x, float y, AnimationFilm *film);
	void Move(int dx, int dy);
	void Display(void);
	void printCoordinates();
	~Sprite();
};

