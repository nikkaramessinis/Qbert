#pragma once

#include "Sprite.h" 
#include "Rect.h" 
#include "SoundManager.h"

struct midline {
	float x, y;
}typedef midline;

class IsoCube {
private:
	midline mid;
	Point * point;
	bool visited;
	Sprite * cube;
	
public:
	int idX, idY;
	bool getVisited(void);
	void setVisited(bool _visited);
	
	void setPoint(float x, float y);
	Point * getPoint(void);

	midline getMid(void);

	int getIdX();
	int getIdY();

	Sprite * getSprite(void);
	//karam
	void setSprite(Sprite *cube);
	IsoCube(int _idX,int _idY,float _x, float _y, bool _visited ,  AnimationFilm* _isoCubeFilm);
};