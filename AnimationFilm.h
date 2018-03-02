#include <vector>
#include "Rect.h"
#include <allegro5/allegro.h>
#include <assert.h>
#include<iostream>
#include <string>
using namespace std;

#pragma once
class AnimationFilm
{
private:
	vector<Rect> boxes;
	ALLEGRO_BITMAP *bitmap;
	string id;
public:
	int GetTotalFrames(void);
	ALLEGRO_BITMAP * GetBitmap(void) const;
	const string GetId(void) const;
	const Rect GetFrameBox(int frameNo) const;
	void DisplayFrame(ALLEGRO_BITMAP *dest, const Point & at, int frameNo) const;
	AnimationFilm(ALLEGRO_BITMAP * _bitmap, const vector<Rect> _boxes, const string& _id);
	~AnimationFilm();
};
