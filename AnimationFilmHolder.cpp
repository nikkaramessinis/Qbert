#include "AnimationFilmHolder.h"

using json = nlohmann::json;

AnimationFilmHolder  *  AnimationFilmHolder::holder = 0;


void AnimationFilmHolder::CleanUp(void)
{
	for (Films::const_iterator i = films.begin(); i != films.end(); ++i)
	{
		delete(i->second);
	}
	films.clear();
}


AnimationFilmHolder::AnimationFilmHolder()
{

}



AnimationFilmHolder::~AnimationFilmHolder()
{
	CleanUp();
}

 AnimationFilmHolder & AnimationFilmHolder::Get(void) 
{
	 if (holder == NULL)
		 holder = new AnimationFilmHolder();
	 return * holder;
}

void AnimationFilmHolder::Load(const string & catalogue)
{
	std::vector<Rect> boxes;
	Rect * tmpRect  ;
	ALLEGRO_BITMAP * bmp;
	string  id ;

	int iterate, iterate2;
	std::ifstream i(catalogue);
	json j;
	i >> j;
	for (iterate = 0; iterate < j["numOfBitmaps"].get<int>(); iterate++) {
		bmp=bitmaps.Load(j["list"][iterate]["path"].get<string>());
		id = j["list"][iterate]["ID"].get<string>();
		tmpRect = new Rect();
		for (iterate2 = 0; iterate2 < j["list"][iterate]["numberOfBoxes"].get<int>(); iterate2++) {
			tmpRect->setX(j["list"][iterate]["ListBoxes"][iterate2]["x"].get<float>());
			tmpRect->setY(j["list"][iterate]["ListBoxes"][iterate2]["y"].get<float>());
			tmpRect->setWidth(j["list"][iterate]["ListBoxes"][iterate2]["w"].get<float>());
			tmpRect->setHeight(j["list"][iterate]["ListBoxes"][iterate2]["h"].get<float>());
			boxes.push_back(*tmpRect);
		}

		films[id] = new AnimationFilm(bmp, boxes, id);
		boxes.clear();
		
	}
}



 AnimationFilm * AnimationFilmHolder::GetFilm(const string id) const
{
	Films::const_iterator i = films.find(id);
	return i != films.end() ? i->second :  (AnimationFilm*) 0;
}
