/*
#pragma once

class BoundingBox;
class BoundingCircle;
class BoundingPolygon;

class BoundingArea
{
protected:
	
	//virtual bool Intersects(const BoundingPolygon& box) const = 0;
public:

	virtual bool Intersects(int test) const = 0;
	virtual bool Intersects(const BoundingBox& box) const = 0;
	virtual bool Intersects(const BoundingCircle& box) const = 0;

	virtual bool In(unsigned x, unsigned y) const = 0;
	virtual bool Intersects(const BoundingArea & area) const = 0;
	virtual BoundingArea* Clone(void) const;

	BoundingArea();
	virtual ~BoundingArea();
};

*/