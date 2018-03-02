#include "Cube.h"


bool IsoCube::getVisited(void)
{
	return visited;
}

void IsoCube::setVisited(bool _visited)
{
	visited = _visited;
}

void IsoCube::setPoint(float x, float y)
{
	point = new Point(x, y);
}

Point * IsoCube::getPoint(void)
{
	return point;
}

midline IsoCube::getMid(void)
{
	return mid;
}

int IsoCube::getIdX()
{
	return idX;
}

int IsoCube::getIdY()
{
	return idY;
}

Sprite * IsoCube::getSprite(void)
{
	return cube;
}

void IsoCube::setSprite(Sprite * _cube)
{
	cube = _cube;
}



IsoCube::IsoCube(int _idX, int _idY, float _x, float _y, bool _visited, AnimationFilm* _isoCubeFilm)
{
	idX = _idX;
	idY = _idY;
	mid.x = 0;
	mid.y = 0;
	visited = _visited;
	cube = new Sprite( _x, _y, _isoCubeFilm);
}
