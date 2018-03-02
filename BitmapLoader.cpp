#include "BitmapLoader.h"



ALLEGRO_BITMAP* BitmapLoader::GetBitmap(const std::string path) const
{
	BitmapMap::const_iterator i = bitmaps.find(path);
	return i != bitmaps.end() ? i->second : (ALLEGRO_BITMAP*)0;
}

ALLEGRO_BITMAP * BitmapLoader::Load(const std::string& path)
{
	
	ALLEGRO_BITMAP* b = GetBitmap(path);
	if (!b)
	{
		bitmaps[path] = (b = al_load_bitmap(path.c_str()));
		assert(b);
	}
	return b;
}


void BitmapLoader::CleanUp(void) {
	for (BitmapMap::iterator i = bitmaps.begin(); i != bitmaps.end(); i++)
	{
		//DestroyBitmap(i->second);
	}
	bitmaps.clear();
}

BitmapLoader::BitmapLoader(void)
{
}


BitmapLoader::~BitmapLoader(void)
{
	CleanUp();
}
