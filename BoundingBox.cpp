/*
#include "BoundingBox.h"



BoundingBox::BoundingBox(float _x1, float _x2, float _y1, float _y2)
	:x1(_x1), y1(_y1), x2(_x2), y2(_y2){}

BoundingBox::~BoundingBox()
{
}

//virtual sinartisi 
bool BoundingBox::Intersects(const BoundingArea& area) const {

	//area.Intersects(1);
	return area.Intersects(*this);
	//area.Intersects((int)1);
}
*/