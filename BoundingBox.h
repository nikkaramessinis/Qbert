/*
#include "BoundingArea.h"

#pragma once
class BoundingBox : public BoundingArea{
protected:
	//!!!!!!!! stis diafanies o savidis to xe unsigned alla epd ta xoume ola san float
	// to vala float
	float x1, y1, x2, y2; // oloklhro to tetragwno
public:
	virtual bool Intersects(const BoundingBox& box) const;
	virtual bool Intersects(const BoundingCircle& circle);
	virtual bool Intersects(const BoundingPolygon* poly);

	virtual bool In(unsigned x, unsigned y) const;
	virtual bool Intersects(const BoundingArea& area) const;
	virtual BoundingBox* Clone(void) const;

	BoundingBox(float _x1, float _x2, float _y1, float _y2);
	~BoundingBox();
};

*/