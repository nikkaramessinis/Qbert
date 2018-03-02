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
#include "Decorations.h"
#include "Moves.h"
#include "Circle.h"
#include "NewMain.h"
#include "SoundManager.h"
#include <windows.h>
#include <fstream>

bool snakeFlag = false;

using json = nlohmann::json;


int circleFlag = 0;
int level = 0;

int dead = 0;
float ms_per_frame = 1 / 60.0;
int frames = 0;
float lastCalc;
IsometricPyramid * Pyramid;
QBERT * Qbert;
Snake *snake;
Ball *Ball1, *Ball2;
Circle *Circle1, *Circle2;
//flag
int Keybord = 1;
const float FPS = 60.0;
ALLEGRO_KEYBOARD_STATE keyState;
bool done;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_TIMER *timer, *timestamp_timer,*coin;
ALLEGRO_TIMER *frametimer;
ALLEGRO_DISPLAY *display;
enum Direction { IDLE = 0, DOWN, LEFT, RIGHT, UP };
bool draw = false;
int idx = 1, idy = 1;
Direction dir = IDLE;
int VisitedCubes = 0;
int indexX = 0, indexY = 0;
int eventFlag = 0;
bool coinInserted = false;
int score = 0;
int sphere_flag = -1;
int sphere_flag2 = -1;
timestamp_t timeStamp = 0;
int leftcount= 0;
int rightcount = 0;
int flag = -1;
int fallflag = -1;
int fallflag2 = -1;
int ticks = 0;
int snakeTicks = 0;
bool snakefell = false;

MovingPathAnimation* rightMove;
MovingPathAnimation* upMove;
MovingPathAnimation* leftMove;
MovingPathAnimation* downMove;

MovingPathAnimation* circleAnimation1;
MovingPathAnimation* circleAnimation2;

MovingPathAnimation* circleUpLeft;
MovingPathAnimation* circleUpRight;

MovingPathAnimation* leftTeleport;
MovingPathAnimation* rightTeleport;

MovingPathAnimation* moveBall1;
MovingPathAnimation* moveRBall1;


MovingPathAnimation* moveBall2;
MovingPathAnimation* moveRBall2;


MovingPathAnimation* fallingRight;
MovingPathAnimation* fallingLeft;
MovingPathAnimation* fallingDownLeft;
MovingPathAnimation* fallingDownRight;


MovingPathAnimation* fallRightBall1;
MovingPathAnimation* fallRightBall2;
MovingPathAnimation* fallDownBall2;
MovingPathAnimation* fallDownBall1;


MovingPathAnimation* SnakeBallRight;
MovingPathAnimation* SnakeBallLeft;

MovingPathAnimation* SnakeLeft;
MovingPathAnimation* SnakeRight;
MovingPathAnimation* SnakeDown;
MovingPathAnimation* SnakeUp;

MovingPathAnimation* SnakeFallLeft;
MovingPathAnimation* SnakeFallRight;
MovingPathAnimator * qbertAnimator;
MovingPathAnimator * circleAnimator1;
MovingPathAnimator * circleAnimator2;
MovingPathAnimator * Ball1animator;
MovingPathAnimator *Ball2animator;
MovingPathAnimator *SnakeAnimator;

int qbertHighScore=0;
Artificial_Intelligence artificialIntelligence;
int counter = 0;
int counter2 = 0;
void Display() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	if (qbertHighScore >= 10000) {
		DrawNumber(qbertHighScore, 745, 190);
	}
	if (qbertHighScore >= 1000) {
		DrawNumber(qbertHighScore, 735, 190);
	}
	else if (qbertHighScore < 1000 && qbertHighScore >= 100) {
		DrawNumber(qbertHighScore, 730, 190);
	}
	else {
		DrawNumber(qbertHighScore, 725, 190);
	}
	
	DrawNumber(score,150,90);
	displayDecorations(Qbert->getLife());
	if (counter != 1) {
		Pyramid->Display();
	}
	Circle1->Display();
	Circle2->Display();
	Qbert->Display();
	if (fallflag == 1) {
		ticks++;
		if (ticks >= 20) {
			ticks = 0;
			counter = 1;
		}
	}

	

	if (counter == 1) {
		Pyramid->Display();
	}
	Ball1->Display();
	Ball2->Display();
	snake->Display(); //rasi! afto na vgei argotera testing skopous

	if (snakeFlag) {
		snakeTicks++;
		if (snakeTicks >= 13) {
			counter2 = 1;
			snakeTicks = 0;
		}
	}

	if (counter2 == 1) {
		Pyramid->Display();
		Qbert->Display();
		Ball1->Display();
		Ball2->Display();
	}

	if (dead == 1) {
		insertCoin->Display();
		gameOver->Display();
		C->Display();
	}
	brisia->Display();
	al_flip_display();
}

void createMap(void) {
	//fortono fotografia me koutakia
	AnimationFilmHolder::Get().Load("JSONS/Cubes.json");
	Pyramid = new IsometricPyramid(
		AnimationFilmHolder::Get().GetFilm("Cubes"),
		400,
		100,
		7,
		448,
		448
	);
	//initialize Cubes
	Pyramid->Create();
}

void KeyBoardInit() {
	event_queue = al_create_event_queue();
	timestamp_timer = al_create_timer(0.001);
	timer = al_create_timer(1 / 90.0);//elegxei 
	frametimer = al_create_timer(0.2);//zwgrafizei
	coin = al_create_timer(1);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timestamp_timer));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(frametimer));
	al_register_event_source(event_queue, al_get_timer_event_source(coin));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_start_timer(timestamp_timer);
	al_start_timer(timer);
	al_start_timer(frametimer);
	al_start_timer(coin);
}

void FPS_Calculation()
{
	frames++;
	float time = al_get_time();
	if (time - lastCalc >= 1.0)
	{
		cout <<"FPS:"<< frames<<endl;
		frames = 0;
		lastCalc = time;
	}
}

void keyHandler(Direction dir) {
	IsoCube*temp;
	if (dir == RIGHT) { idx += 1; idy += 1; }
	else if (dir == LEFT) { idx -= 1; idy -= 1; }
	else if (dir == UP) { idy -= 1; }
	else if (dir == DOWN) { idy += 1; }
	//rasiii setaroyme ton qbert gia na exei access to AI
	Qbert->qbertLastX = Qbert->getCubeX();
	Qbert->qbertLastY = Qbert->getCubeY();
	Qbert->setCubeX(idx);
	Qbert->setCubeY(idy);
	//soundd
	SoundManager::playQbertJump();
	temp = Pyramid->SearchById(idy, idx);

	if (idx == 0 && idy == 4 && leftcount == 0) {
		//animation
		sphere_flag = 0;
		sphere_flag2 = 0;
		//sound
		SoundManager::playDiskRide();
		/*idy = 1;
		idx = 1;*/

		/*Qbert->setCubeX(0);
		Qbert->setCubeY(5);*/

		flag = 1;
		leftcount++;
		Qbert->collisionSensitive = false;
	}
	else if (idx == 5 && idy == 4 && rightcount == 0) {
		//animation
		Qbert->collisionSensitive = false;
		sphere_flag = 1;
		sphere_flag2 = 1;
		/*idy = 1;
		idx = 1;*/

		/*Qbert->setCubeX(4);
		Qbert->setCubeY(5);*/

		flag = 1;
		//sound
		SoundManager::playDiskRide();
		rightcount++;
	}
	else if ((temp == NULL)) {
		Qbert->collisionSensitive = false;
		if (idx == 0) {
			fallflag = 1;
			qbertAnimator->Start(Qbert->GetSprite(), fallingLeft, timeStamp);
			AnimatorHolder::Get().MarkAsRunning(qbertAnimator);
			Qbert->collisionSensitive = false;
			

		}
		else if (idy == 8)
		{

			if (dir == DOWN) {
				fallflag2 = 1;
				qbertAnimator->Start(Qbert->GetSprite(), fallingDownLeft, timeStamp);
				AnimatorHolder::Get().MarkAsRunning(qbertAnimator);

			}
			else if (dir == RIGHT)
			{
				fallflag2 = 1;
				qbertAnimator->Start(Qbert->GetSprite(), fallingDownRight, timeStamp);
				AnimatorHolder::Get().MarkAsRunning(qbertAnimator);
			}
		}
		else {
			fallflag = 1;
			qbertAnimator->Start(Qbert->GetSprite(), fallingRight, timeStamp);
			AnimatorHolder::Get().MarkAsRunning(qbertAnimator);
		}
		SoundManager::playQbertFalling();
	}
}


void changeCube(void) {
	IsoCube*temp;
	temp = Pyramid->SearchById(idy, idx);
		if (!temp->getVisited()) {
			temp->getSprite()->SetFrame(level+1);
			VisitedCubes++;
			temp->setVisited(true);
			if (score == qbertHighScore) {
				score += 25;
				qbertHighScore = score;
			}
			else {
				score += 25;
			}
		}
	}



void CreatInit() {
	createMap();
	CreateDecorations();
}

void getCoin() {
	ALLEGRO_EVENT events;
	al_wait_for_event(event_queue, &events);
	al_get_keyboard_state(&keyState);
	if (events.type == ALLEGRO_EVENT_TIMER) {
		if (al_key_down(&keyState, ALLEGRO_KEY_C) && dead == 1) {
			//to vazw prosorina etsi giati patiete poli grigora
			coinInserted = true;
			SoundManager::playInsertCoin();

			coinInserted = false;
			dead = 0;
			Qbert->setLife(3);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE) && dead == 1) {
			//to vazw prosorina etsi giati patiete poli grigora
			//coinInserted = true;
			ofstream myfile;
			myfile.open("HighScore/highScore.txt");
			myfile << score;
			myfile.close();
			//highScore
			SoundManager::QbertBye();
			Sleep(1000);
			exit(1);
		}
	}
}

void Event() {
	if (eventFlag == -1) {

		return;
	}
	if (circleFlag != 0) {
		return;
	}
	ALLEGRO_EVENT events;
	al_wait_for_event(event_queue, &events);
	al_get_keyboard_state(&keyState);
	//kleinei to parathuro
	if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		done = true;
	}
	else if (events.type == ALLEGRO_EVENT_TIMER) {
		if (Keybord == 1) {
			if (events.timer.source == timer) {
				if (al_key_down(&keyState, ALLEGRO_KEY_DOWN) && dead==0) {
					//KATW ARISTERA
					dir = DOWN;
					Keybord = -1;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_UP) && dead == 0) {
					//PANW DEKSIA
					dir = UP;
					Keybord = -1;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT) && dead == 0) {
					dir = LEFT;
					Keybord = -1;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT) && dead == 0) {
					dir = RIGHT;
					Keybord = -1;
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_C) && dead == 1) {
					//to vazw prosorina etsi giati patiete poli grigora
					coinInserted = true;
					SoundManager::playInsertCoin();

					coinInserted = false;
					dead = 0;
					Qbert->setLife(3);
				}
			}
		}
		if (events.timer.source == frametimer) {
			if (dir == UP) {
				eventFlag = -1;
				//timeStamp = 0;
				qbertAnimator->Start(Qbert->GetSprite(), upMove, timeStamp);
				AnimatorHolder::Get().MarkAsRunning(qbertAnimator);
				keyHandler(dir);
			}
			else if (dir == DOWN) {
				eventFlag = -1;
				//timeStamp = 0;
				qbertAnimator->Start(Qbert->GetSprite(), downMove, timeStamp);
				AnimatorHolder::Get().MarkAsRunning(qbertAnimator);
				keyHandler(dir);
			}
			else if (dir == LEFT) {
				eventFlag = -1;
				//timeStamp = 0;
				qbertAnimator->Start(Qbert->GetSprite(), leftMove, timeStamp);
				AnimatorHolder::Get().MarkAsRunning(qbertAnimator);
				keyHandler(dir);
			}
			else if (dir == RIGHT) {
				eventFlag = -1;
				//timeStamp=0;
				qbertAnimator->Start(Qbert->GetSprite(), rightMove, timeStamp);
				AnimatorHolder::Get().MarkAsRunning(qbertAnimator);
				keyHandler(dir);
			}

			if (coinInserted) {
				if (Qbert->getLife() < 3) {//prosorina to vazw etsi giati tsekarei gia isotita sto display lives
				
					/*SoundManager::playInsertCoin();

					coinInserted = false;
					dead = 0;
					Qbert->setLife(3);*/
				}
			}

		}
	}
}
void timestamp_incr() {
	ALLEGRO_EVENT events;
	al_wait_for_event(event_queue, &events);
	if (events.type == ALLEGRO_EVENT_TIMER) {
		if (events.timer.source == timestamp_timer) {
			timeStamp++;
		}
	}
}


void isDead(void) {
	ALLEGRO_EVENT events;
	
	if (Qbert->getLife() <= 0) {
		dead = 1;
		while (dead) {
			al_wait_for_event(event_queue, &events);
			if (events.type == ALLEGRO_EVENT_TIMER) {
				if (events.timer.source == coin) {
					if (!(C->IsVisible())) {
						C->SetVisibility(true);
					}
					else {
						C->SetVisibility(false);
					}
				}
			}
			Display();
			getCoin();
		}
		artificialIntelligence.startBotsFromBeginning();
	}
}

void winGame(void) {
	int times=0;
	unsigned flag=0;
	SoundManager::playGameStart();

	if (level == 0) {
		while (times < 20) {
			Sleep(100);
			times++;
			Pyramid->SetCurrFrameAll(flag);
			if (flag == 1) {
				flag = 0;
			}
			else {
				flag = 1;
			}
			Display();
		}
		changeDec2->SetVisibility(true);
		Pyramid->SetCurrFrameAll(2);
		VisitedCubes = 0;
		Qbert->GetSprite()->setX1(383);
		Qbert->GetSprite()->setY1(133);
		Qbert->setCubeX(1);
		Qbert->setCubeY(1);
		idx = 1; idy = 1;
		level = 2;
		//roundDec->SetFrame(1);
	}
	else {
		while (times < 20) {
			Sleep(100);
			times++;
			Pyramid->SetCurrFrameAll(flag+2);
			if (flag == 1) {
				flag = 0;
			}
			else {
				flag = 1;
			}
			Display();
		}
		changeDec2->SetVisibility(false);
		Pyramid->SetCurrFrameAll(0);
		VisitedCubes = 0;
		Qbert->GetSprite()->setX1(383);
		Qbert->GetSprite()->setY1(133);
		Qbert->setCubeX(1);
		Qbert->setCubeY(1);
		idx = 1; idy = 1;
		level = 0;
		//roundDec->SetFrame(1);
	}
	counter2 = 0;
		artificialIntelligence.startBotsFromBeginning();
		Circle1->GetSprite()->SetVisibility(true);
		Circle1->GetSprite()->setX1(224);
		Circle1->GetSprite()->setY1(295);
		Circle2->GetSprite()->SetVisibility(true);
		Circle2->GetSprite()->setX1(544);
		Circle2->GetSprite()->setY1(295);
		leftcount = 0;
		rightcount = 0;
		if (numberLevelDec->GetFrame() < 9 && numberLevelDec2->IsVisible()==false) {
			numberLevelDec->SetFrame(numberLevelDec->GetFrame() + 1);
		}
		else if (numberLevelDec->GetFrame() == 9) {
			numberLevelDec2->SetVisibility(true);
			numberLevelDec->SetFrame(1);
		}
		else {
			numberLevelDec2->SetFrame(numberLevelDec2->GetFrame() + 1);
		}
		Display();
}

void execute() {
	if (VisitedCubes == 28) { 
		winGame();
	}

	isDead();
	if (sphere_flag2 == 0) {
		if (qbertAnimator->HasFinished()) {
			AnimatorHolder::Get().MarkAsSuspended(qbertAnimator);
			qbertAnimator->Start(Qbert->GetSprite(), leftTeleport, timeStamp);
			AnimatorHolder::Get().MarkAsRunning(qbertAnimator);

			circleAnimator1->Start(Circle1->GetSprite(), circleUpLeft, timeStamp);
			AnimatorHolder::Get().MarkAsRunning(circleAnimator1);
			eventFlag = -1;
			dir = IDLE;
			eventFlag = -1;
			Keybord = 1;
			sphere_flag2 = -1;
			circleFlag = 1;
		}

	}

	if (sphere_flag2 == 1) {
		if (qbertAnimator->HasFinished()) {
			AnimatorHolder::Get().MarkAsSuspended(qbertAnimator);
			qbertAnimator->Start(Qbert->GetSprite(), rightTeleport, timeStamp);
			AnimatorHolder::Get().MarkAsRunning(qbertAnimator);

			circleAnimator2->Start(Circle2->GetSprite(), circleUpRight, timeStamp);
			AnimatorHolder::Get().MarkAsRunning(circleAnimator2);
			eventFlag = -1;
			dir = IDLE;
			eventFlag = 0;
			Keybord = 1;
			sphere_flag2 = -1;
			circleFlag = 1;
		}

	}
	if (SnakeAnimator->HasFinished() && snakefell==true) {
		artificialIntelligence.startBotsFromBeginning(); 
		snakefell = false;
	
	}

	if (circleAnimator1->HasFinished()) {
		AnimatorHolder::Get().MarkAsSuspended(circleAnimator1);
		circleAnimator1->Start(Circle1->GetSprite(), circleAnimation1, timeStamp);
		if (flag == 1) {
			AnimatorHolder::Get().MarkAsSuspended(qbertAnimator);
			qbertAnimator->Start(Qbert->GetSprite(), rightMove, timeStamp);
			AnimatorHolder::Get().MarkAsRunning(qbertAnimator); flag = -1;
			Circle1->GetSprite()->SetVisibility(false);

			Qbert->collisionSensitive = true;
			Qbert->setCubeX(1);
			Qbert->setCubeY(1);
			idy = 1;
			idx = 1;
			sphere_flag = -1;

		}

		
		dir = IDLE;
		eventFlag = 0;
		Keybord = 1;
		
	}

	if (circleAnimator2->HasFinished()) {
		AnimatorHolder::Get().MarkAsSuspended(circleAnimator2);
		circleAnimator2->Start(Circle2->GetSprite(), circleAnimation2, timeStamp);
		if (flag == 1) {
			AnimatorHolder::Get().MarkAsSuspended(qbertAnimator);
			qbertAnimator->Start(Qbert->GetSprite(), downMove, timeStamp);
			AnimatorHolder::Get().MarkAsRunning(qbertAnimator); flag = -1;
			Circle2->GetSprite()->SetVisibility(false);

			Qbert->collisionSensitive = true;
			Qbert->setCubeX(1);
			Qbert->setCubeY(1);
			idy = 1;
			idx = 1;
			sphere_flag = -1;
		}
		dir = IDLE;
		eventFlag = 0;
		Keybord = 1;
	}

	if (qbertAnimator->HasFinished()) {

		if (circleFlag != 0) {
			circleFlag--;
		}

		if (fallflag == 1 || fallflag2 == 1) {
			Qbert->collisionSensitive = true;
			fallflag = 0;
			fallflag2 = 0;
			if (Qbert->getLife() > 0) {
				Qbert->setLife(Qbert->getLife() - 1);
			} //decrement kata 1
			Qbert->GetSprite()->setX1(383);
			Qbert->GetSprite()->setY1(133);
			Qbert->setCubeX(1);
			Qbert->setCubeY(1);
			artificialIntelligence.startBotsFromBeginning();
			Qbert->GetSprite()->SetFrame(0);
			idx = 1; idy = 1;
			counter = 0;

			Qbert->collisionSensitive = true;

		}
		AnimatorHolder::Get().MarkAsSuspended(qbertAnimator);
		qbertAnimator->Start(Qbert->GetSprite(), leftMove, timeStamp);
		dir = IDLE;
		changeCube();
		eventFlag = 0;
		Keybord = 1;

		if (VisitedCubes == 28) {
			winGame();
		}

	}

	if (Ball1animator->HasFinished())
	{
		AnimatorHolder::Get().MarkAsSuspended(Ball1animator);
		Ball1animator->Start(Ball1->GetSprite(), moveRBall1, timeStamp);

	}


	if (SnakeAnimator->HasFinished())
	{
		AnimatorHolder::Get().MarkAsSuspended(SnakeAnimator);
		SnakeAnimator->Start(snake->GetSprite(), SnakeDown, timeStamp);

	}

	if (Ball2animator->HasFinished())
	{
		AnimatorHolder::Get().MarkAsSuspended(Ball2animator);
		Ball2animator->Start(Ball2->GetSprite(), moveRBall2, timeStamp);
	}
	AnimatorHolder::Get().Progress(timeStamp);
	
	isDead();
}

void death(){
	IsoCube*temp;
	SoundManager::Qbertdie();
	brisia->setX1(Qbert->GetSprite()->getX1());
	brisia->setY1(Qbert->GetSprite()->getY1() - 50);
	brisia->SetVisibility(true);
	Display();
	Sleep(1000);
	brisia->SetVisibility(false);
}


int main() {

	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "Could not load Allegro5", NULL, NULL); return -1;
	}
	al_init_image_addon();
	al_install_keyboard();
	//al_install_audio();
	al_init_acodec_addon();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	display = al_create_display(800, 600);
	al_set_window_position(display, 200, 100);
	al_set_window_title(display, "HY454");

	SoundManager soundManager;

	//gameStart sound
	SoundManager::playGameStart();


	if (!display) {
		al_show_native_message_box(display, "Sample", "Display Settings", "Display Window", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	done = false;
	Intro();
	//create map and decorations
	CreatInit();
	initMoves();
	//Artificial_Intelligence artificialIntelligence;
	CollisionManager collisionManager;

	AnimationFilmHolder::Get().Load("JSONS/qbert.json");
	AnimationFilmHolder::Get().Load("JSONS/snake.json");
	AnimationFilmHolder::Get().Load("JSONS/ball.json");
	AnimationFilmHolder::Get().Load("JSONS/circle.json");
	AnimationFilmHolder::Get().Load("JSONS/snakeBall.json");




	
	//dhmiourgia qbert
	IsoCube* first = Pyramid->SearchById(idx, idy);
	
	
	Point *p = new Point(first->getPoint()->x, first->getPoint()->y);
	Qbert = new QBERT(p, AnimationFilmHolder::Get().GetFilm("walk_right"));
	Qbert->Display();
	collisionManager.addQbert(Qbert->GetSprite()); //!! addQbert kalw edw
	collisionManager.setQbertClassObject(Qbert);
	//dhmiourgia snake
	SnakeAnimator = new MovingPathAnimator();
	snake = new Snake(new Point(0, 0), AnimationFilmHolder::Get().GetFilm("snakeBall"),SnakeAnimator, SnakeLeft, SnakeBallRight,SnakeBallLeft,SnakeUp);
	snake->Display();

	//snake->collisionManager = &collisionManager;

	//collisionManager.addBot(snake->GetSprite()); //!! addBot kalw edw
	



	Ball1animator = new MovingPathAnimator();
	//dhmiourgia Ball1
	Ball1 = new Ball(new Point(0, 0), AnimationFilmHolder::Get().GetFilm("redBall"), Ball1animator, moveBall1, moveRBall1);
	Ball1->Display();
	collisionManager.addBot(Ball1->GetSprite()); //!! addBot kalw edw

	Ball2animator = new MovingPathAnimator();
	//dhmiourgia Ball2;
	Ball2 = new Ball(new Point(0, 0), AnimationFilmHolder::Get().GetFilm("redBall"), Ball2animator, moveBall2, moveRBall2);
	Ball2->Display();
	collisionManager.addBot(Ball2->GetSprite()); //!! addBot kalw edw

												 //dhmiourgia circles
	Circle1 = new Circle(new Point(224, 295), AnimationFilmHolder::Get().GetFilm("1"));
	Circle1->Display();
	//collisionManager.addBot(Circle1->GetSprite()); //!! addBot kalw edw*/


	//telika thesh 326,148 
	/*Circle1 = new Circle(new Point(326, 148), AnimationFilmHolder::Get().GetFilm("1"));
	Circle1->Display();
	collisionManager.addBot(Circle1->GetSprite()); //!! addBot kalw edw*/

	Circle2 = new Circle(new Point(544, 295), AnimationFilmHolder::Get().GetFilm("1"));
	Circle2->Display();
	//collisionManager.addBot(Circle2->GetSprite()); //!! addBot kalw edw


	artificialIntelligence.setBall1(Ball1);
	artificialIntelligence.setBall2(Ball2);
	artificialIntelligence.setSnake(snake);
	artificialIntelligence.setQbert(Qbert);

	KeyBoardInit();



	//animators Initializing
	qbertAnimator = new MovingPathAnimator();
	AnimatorHolder::Get().Register(qbertAnimator);
	circleAnimator1 = new MovingPathAnimator();
	AnimatorHolder::Get().Register(circleAnimator1);
	circleAnimator2 = new MovingPathAnimator();
	AnimatorHolder::Get().Register(circleAnimator2);
	AnimatorHolder::Get().Register(Ball1animator);
	AnimatorHolder::Get().Register(Ball2animator);
	double previous = al_get_time();
	double lag = 0.0;

	qbertAnimator->Start(Qbert->GetSprite(), leftMove, timeStamp);

	collisionManager.ai = &artificialIntelligence;
	//collisionManager.addBot(AnimationFilmHolder::Get().GetFilm("snakeBall").);

	snake->ballSnakeSprite = new Sprite(1,1,AnimationFilmHolder::Get().GetFilm("snakeBall"));
	snake->snakeBodySprite = new Sprite(1, 1, AnimationFilmHolder::Get().GetFilm("snake"));
	snake->setSprite(snake->ballSnakeSprite);
	snake->SnakeSprite->SetVisibility(false);
	collisionManager.addBot(snake->ballSnakeSprite);
	collisionManager.addBot(snake->snakeBodySprite);

	ifstream myfile;
	myfile.open("HighScore/highScore.txt");
	myfile >> qbertHighScore;
	myfile.close();


	Ball1->isAlive = false;
	Ball1->isAlive = false;

	while (!done) {


		double start = al_get_time();

		Display();
		execute();
		timestamp_incr();
		if (collisionManager.collisionCheck()) {
			death();
		}
		draw = artificialIntelligence.run(timeStamp);

		while (al_get_time() - start <= ms_per_frame) {
			Event();
		}
		//FPS_Calculation();
	}

	al_destroy_timer(timer);
	al_destroy_timer(frametimer);
	//al_destroy_bitmap(terrain);
	//al_destroy_display(display);
	//al_destroy_sample(qbertJumpSound);
}