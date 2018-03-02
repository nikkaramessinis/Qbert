#pragma once

#include <allegro5/allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <iostream>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <string>
#include <map>

//prepei na einai private kanonika
//einai public gia test logous
class BitmapLoader
{
private:
	typedef std::map <std::string, ALLEGRO_BITMAP*> BitmapMap;
	BitmapMap bitmaps;


public:
	ALLEGRO_BITMAP * GetBitmap(const std::string path) const;
	ALLEGRO_BITMAP * Load(const std::string& path);
	void CleanUp(void);
	BitmapLoader();
	~BitmapLoader();
};

