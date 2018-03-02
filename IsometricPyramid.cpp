#include "IsometricPyramid.h"

void IsometricPyramid::SetCurrFrameAll(unsigned frame)
{
	for (vector<IsoCube *>::iterator it = isoCubes.begin(); it != isoCubes.end(); ++it) {
			(*it)->getSprite()->SetFrame(frame);
			(*it)->setVisited(false);
	}
}

IsometricPyramid::IsometricPyramid(AnimationFilm * _isoCubeFilm, float _Px, float _Py, float _totalRows, float _totalWidth, float _totaHeight)
{
	isoCubeFilm = _isoCubeFilm;
	Px = _Px;
	Py = _Py;
	totalRows = _totalRows;
	totalWidth = _totalWidth;
	totaHeight = _totaHeight;
}

void IsometricPyramid::Create(void)
{

	float currentX,firstX,currentY;
	IsoCube * _isoCubes;
	firstX = Px;
	currentY = Py;
	for (int i = 0; i < 7; i++) {
		currentY += 48; firstX -= 32; currentX = firstX;
		for (int j = 0; j <= i; j++) {
			_isoCubes = new IsoCube(i+1,j+1,currentX, currentY, false, isoCubeFilm);
			_isoCubes->setPoint(currentX+15, currentY-15);
			//theto na einai visible
			_isoCubes->getSprite()->SetVisibility(true);
			//theto frameNo
			_isoCubes->getSprite()->SetFrame(0);
			isoCubes.push_back(_isoCubes);
			currentX += 64;
		}
	}
}

void IsometricPyramid::Display(void)
{
	for (vector<IsoCube *>::iterator it = isoCubes.begin(); it != isoCubes.end(); ++it) {
		(*it)->getSprite()->Display();
		
	}
	//al_flip_display();
}

IsoCube * IsometricPyramid::SearchById(int idX, int idY)
{
	for (vector<IsoCube *>::iterator it = isoCubes.begin(); it != isoCubes.end(); ++it) {
		if ((*it)->getIdX()== idX && (*it)->getIdY() == idY) {
			return (*it);
		}
	}return NULL;
}
