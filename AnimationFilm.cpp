#include "AnimationFilm.h"

int AnimationFilm::GetTotalFrames(void)
{
	return boxes.size();
}

ALLEGRO_BITMAP * AnimationFilm::GetBitmap(void) const
{
	return bitmap;
}

const string AnimationFilm::GetId(void) const
{
	return id;
}

const Rect AnimationFilm::GetFrameBox(int frameNo) const
{
	assert(boxes.size() > frameNo);
	return boxes[frameNo];
}

void AnimationFilm::DisplayFrame(ALLEGRO_BITMAP * dest, const Point & at, int frameNo) const
{
	Rect box = GetFrameBox(frameNo);
	al_draw_bitmap_region(dest, box.getX(), box.getY(), box.getWidth(), box.getHeight() , at.x, at.y, 0);
}

AnimationFilm::AnimationFilm(ALLEGRO_BITMAP * _bitmap, const vector<Rect> _boxes, const string & _id)
	:boxes(_boxes), bitmap(_bitmap), id(_id) {}

AnimationFilm::~AnimationFilm()
{
}