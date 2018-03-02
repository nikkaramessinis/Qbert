#include <allegro5/allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <iostream>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include "AnimationFilmHolder.h"
#include "IsometricPyramid.h"
#include "MovingPathAnimator.h"
#include "QBERT.h"
#include "Snake.h"
#include "CollisionManager.h"
#include "Artificial_Intelligence.h"
#include "Ball.h"
#include "json.hpp"
#include "AnimatorHolder.h"
#include <windows.h>

#include <iostream>
#include <conio.h>

#pragma once

//decorations
Sprite * playerDec;
Sprite * playerNumDec;
Sprite * changetoDec;
Sprite * changeDec;
Sprite * changeDec2;
Sprite * numbersDec;
Sprite * levelDec;
Sprite * numberLevelDec;
Sprite * numberLevelDec2;
Sprite * roundDec;
Sprite * numberRoundDec;
Sprite * logotupoDec;
Sprite * heart1,*heart2,*heart3;
Sprite *  logo;
Sprite * logoname;
Sprite *smallname;
Sprite * insertCoin;
Sprite * gameOver;
Sprite * C;
Sprite * brisia;
Sprite * highScore;


void Intro() {
	ALLEGRO_FONT *font = al_load_font("Resources/orbitron-black.ttf", 14, NULL);
	ALLEGRO_FONT *font2 = al_load_font("Resources/orbitron-black.ttf", 18, NULL);
	//ALLEGRO_BITMAP * name = load_bitmap_at_size("Resources/QBERT.png", 600, 150);//destroy bitmaps
	//al_draw_bitmap(name, 100, 0, NULL);

	AnimationFilmHolder::Get().Load("JSONS/decorations/logo.json");
	logo  = new Sprite(220, 110, AnimationFilmHolder::Get().GetFilm("logo"));
	logo->SetFrame(0);
	logo->SetVisibility(true);
	logo->Display();
	
	
	
	AnimationFilmHolder::Get().Load("JSONS/decorations/name.json");
	logoname = new Sprite(170, 0, AnimationFilmHolder::Get().GetFilm("name"));
	logoname->SetFrame(0);
	logoname->SetVisibility(true);
	logoname->Display();



	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 505, ALLEGRO_ALIGN_CENTER, "University of Crete");
	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 520, ALLEGRO_ALIGN_CENTER, "Department of Computer Science");
	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 535, ALLEGRO_ALIGN_CENTER, "CS454 Development of Intelligent Interfaces and Games");
	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 550, ALLEGRO_ALIGN_CENTER, "Term Project, Fall Semester 2017");
	al_draw_text(font2, al_map_rgb(255, 255, 255), 400, 570, ALLEGRO_ALIGN_CENTER, "Nikos Karamessinis Christos Athinaiou Alexis Rasidakis");
	
	al_flip_display();
	//al_rest(7.0);
	Sleep(500);
	al_clear_to_color(al_map_rgb(0, 0, 0));
}


void CreateDecorations() {
	//decorations

	AnimationFilmHolder::Get().Load("JSONS/decorations/highScore.json");
	highScore = new Sprite(550, 190, AnimationFilmHolder::Get().GetFilm("highScore"));
	highScore->SetFrame(0);
	highScore->SetVisibility(true);

	AnimationFilmHolder::Get().Load("JSONS/decorations/brisia.json");
	brisia = new Sprite(320, 335, AnimationFilmHolder::Get().GetFilm("brisia"));
	brisia->SetFrame(0);
	brisia->SetVisibility(false);

	AnimationFilmHolder::Get().Load("JSONS/decorations/C.json");
	C = new Sprite(320, 335, AnimationFilmHolder::Get().GetFilm("C"));
	C->SetFrame(0);
	C->SetVisibility(true);

	AnimationFilmHolder::Get().Load("JSONS/decorations/insertCoin.json");
	insertCoin = new Sprite(200, 250, AnimationFilmHolder::Get().GetFilm("insertCoin"));
	insertCoin->SetFrame(0);
	insertCoin->SetVisibility(true);

	AnimationFilmHolder::Get().Load("JSONS/decorations/gameOver.json");
	gameOver = new Sprite(230, 170, AnimationFilmHolder::Get().GetFilm("gameOver"));
	gameOver->SetFrame(0);
	gameOver->SetVisibility(true);

	AnimationFilmHolder::Get().Load("JSONS/decorations/player.json");
	playerDec = new Sprite(30, 50, AnimationFilmHolder::Get().GetFilm("player"));
	playerDec->SetFrame(0);
	playerDec->SetVisibility(true);

	AnimationFilmHolder::Get().Load("JSONS/decorations/1.json");
	playerNumDec = new Sprite(180, 50, AnimationFilmHolder::Get().GetFilm("1"));
	playerNumDec->SetFrame(0);
	playerNumDec->SetVisibility(true);

	AnimationFilmHolder::Get().Load("JSONS/decorations/changeto.json");
	changetoDec = new Sprite(30, 130, AnimationFilmHolder::Get().GetFilm("changeto"));
	changetoDec->SetFrame(0);
	changetoDec->SetVisibility(true);

	AnimationFilmHolder::Get().Load("JSONS/decorations/change.json");
	changeDec = new Sprite(70, 150, AnimationFilmHolder::Get().GetFilm("change"));
	changeDec->SetFrame(0);
	changeDec->SetVisibility(true);

	AnimationFilmHolder::Get().Load("JSONS/decorations/change2.json");
	changeDec2 = new Sprite(70, 150, AnimationFilmHolder::Get().GetFilm("change2"));
	changeDec2->SetFrame(0);
	changeDec2->SetVisibility(false);

	AnimationFilmHolder::Get().Load("JSONS/decorations/smallname.json");
	smallname = new Sprite(420, 20, AnimationFilmHolder::Get().GetFilm("smallname"));
	smallname->SetFrame(0);
	smallname->SetVisibility(true);
	
	
	AnimationFilmHolder::Get().Load("JSONS/decorations/level.json");
	levelDec = new Sprite(600, 130, AnimationFilmHolder::Get().GetFilm("level"));
	levelDec->SetFrame(0);
	levelDec->SetVisibility(true);


	AnimationFilmHolder::Get().Load("JSONS/decorations/numbers.json");
	numberLevelDec = new Sprite(700, 127, AnimationFilmHolder::Get().GetFilm("numbers"));
	numberLevelDec->SetFrame(0);
	numberLevelDec->SetVisibility(true);

	numberLevelDec2 = new Sprite(720, 127, AnimationFilmHolder::Get().GetFilm("numbers"));
	numberLevelDec2->SetFrame(0);
	numberLevelDec2->SetVisibility(false);

	AnimationFilmHolder::Get().Load("JSONS/decorations/round.json");
	roundDec = new Sprite(600, 160, AnimationFilmHolder::Get().GetFilm("round"));
	roundDec->SetFrame(0);
	roundDec->SetVisibility(true);

	numberRoundDec = new Sprite(700, 157, AnimationFilmHolder::Get().GetFilm("numbers"));
	numberRoundDec->SetFrame(1);
	numberRoundDec->SetVisibility(true);

	/* 
	AnimationFilmHolder::Get().Load("JSONS/decorations/logotupo.json");
	logotupoDec = new Sprite(385, 60, AnimationFilmHolder::Get().GetFilm("logotupo"));
	logotupoDec->SetFrame(0);
	logotupoDec->SetVisibility(true);
	*/

	AnimationFilmHolder::Get().Load("JSONS/decorations/heart.json");
	heart1 = new Sprite(30, 220, AnimationFilmHolder::Get().GetFilm("heart"));
	heart1->SetFrame(0);
	heart1->SetVisibility(true);
	

	heart2 = new Sprite(70, 220, AnimationFilmHolder::Get().GetFilm("heart"));
	heart2->SetFrame(0);
	heart2->SetVisibility(true);

	heart3= new Sprite(110, 220, AnimationFilmHolder::Get().GetFilm("heart"));
	heart3->SetFrame(0);
	heart3->SetVisibility(true);

}


void DrawNumber(int number,int x,int y) {
	int displaynum, newnumber = number, digit = 0;
	while (newnumber!= 0) {
		displaynum = newnumber % 10;
		newnumber = newnumber / 10;
		numbersDec = new Sprite(x-digit*20 ,y, AnimationFilmHolder::Get().GetFilm("numbers"));
		numbersDec->SetFrame(displaynum);
		numbersDec->SetVisibility(true);
		numbersDec->Display();
		digit++;
	}
	if(number==0){
		numbersDec = new Sprite(x - digit * 20, y, AnimationFilmHolder::Get().GetFilm("numbers"));
		numbersDec->SetFrame(0);
		numbersDec->SetVisibility(true);
		numbersDec->Display();
	}



}
void diplayLives(int lives) {
	if (lives == 3) {
		heart1->Display();
		heart2->Display();
		heart3->Display();
	}
	else if (lives == 2) {
		heart1->Display();
		heart2->Display();
		
	}
	else if (lives == 1) {
		heart1->Display();
	}
}
void displayDecorations(int lives1) {
		playerDec->Display();
		playerNumDec->Display();
		changetoDec->Display();
		changeDec->Display();
		levelDec->Display();
		numberLevelDec->Display();
		numberLevelDec2->Display();
		roundDec->Display();
		numberRoundDec->Display();
		smallname->Display();
		//logotupoDec->Display();
		diplayLives(lives1);
		changeDec2->Display();
		highScore->Display();
	}





