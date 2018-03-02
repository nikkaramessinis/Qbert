#pragma once
//used for animationFilm 
class Rect
{
private:
	float x; //x axis
	float y; //y axis
	float w; //width
	float h; //height

public:
	float getX(void);
	void setX(float x);
	
	float getY(void);
	void  setY(float y);
	
	float getWidth(void);
	void  setWidth(float w);
	
	float getHeight(void);
	void  setHeight(float h);

	Rect(); //default constructor rasi
	Rect(float _x, float _y, float _w, float _h);

	void toString();

	~Rect();
};

class Point {
public:
	float x, y;
	Point();
	Point(float _x, float _y);
};