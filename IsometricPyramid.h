#pragma once
#include "sprite.h"
#include "Cube.h"
#include <vector>
#include "Rect.h"


using namespace std;
class IsometricPyramid 
{
private:
	float Px, Py;
	float totalRows;
	float totalWidth;
	float totaHeight;
	vector<IsoCube *> isoCubes;
	AnimationFilm* isoCubeFilm;
public:
	void Create(void);
	void Display(void);
	void Destroy(void); // normally at level program end
	IsoCube * SearchById(int idX, int idY);
	unsigned GetTotalWidth(void) const;
	unsigned GetTotalHeight(void) const;
	void SetZOrder(unsigned zOrder); // for all sprites
	void SetCurrFrame(unsigned row, unsigned col, unsigned frame);
	void SetCurrFrameAll(unsigned frame);
	Sprite* GetIsoCube(unsigned row, unsigned col);
	IsometricPyramid(
		AnimationFilm* _isoCubeFilm,
		float _Px,
		float _Py,
		float _totalRows,
		float _totalWidth,
		float _totaHeight
	);
};

