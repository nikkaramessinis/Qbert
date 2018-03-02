#ifndef ANIMETIONFILMHOLDER_H
#define ANIMETIONFILMHOLDER_H

#include <map>
#include <string>
#include "AnimationFilm.h"
#include <allegro5\allegro.h>
#include "BitmapLoader.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include "Rect.h"
#include <vector>
using namespace std;
class AnimationFilmHolder
{
private :
	typedef map<string, AnimationFilm *> Films;
	Films	films;
	BitmapLoader bitmaps;
	static AnimationFilmHolder * holder;//singleton
	AnimationFilmHolder();
	~AnimationFilmHolder();
public:
	   static AnimationFilmHolder& Get(void);
	   void Load(const string& catalogue);
	   void CleanUp(void);
	   AnimationFilm* GetFilm(const string id) const;

				
};


#endif