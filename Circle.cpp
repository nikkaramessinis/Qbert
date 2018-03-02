#include "Circle.h"



Circle::Circle(Point * p, AnimationFilm * film)
{
	circleSprite = new Sprite(p->x, p->y, film);
	circleSprite->SetVisibility(true);
	circleSprite->SetFrame(0);

}

void Circle::Display()
{
	circleSprite->Display();
}
Sprite*		Circle::GetSprite() {
	return circleSprite;
}
Circle::~Circle()
{
}

