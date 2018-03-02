#include "Rect.h"
#include "Sprite.h"
class Circle
{
	Sprite * circleSprite;
	bool visible;
public:
	Circle(Point * p, AnimationFilm *film);
	void Display();

	Sprite * GetSprite();
	~Circle();
};

