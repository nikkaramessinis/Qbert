#pragma once

#include "MovingPathAnimator.h"
#include "json.hpp"
#include <iostream>
#include <fstream>

using namespace std;

using json = nlohmann::json;

extern MovingPathAnimation* rightMove;
extern MovingPathAnimation* upMove;
extern MovingPathAnimation* leftMove;
extern MovingPathAnimation* downMove;
extern MovingPathAnimation* circleAnimation1;
extern MovingPathAnimation* circleAnimation2;
extern MovingPathAnimation* circleUpLeft;
extern MovingPathAnimation* circleUpRight;
extern MovingPathAnimation* leftTeleport;
extern MovingPathAnimation* rightTeleport;
extern MovingPathAnimation* moveBall1;
extern MovingPathAnimation* moveRBall1;
extern MovingPathAnimation* moveBall2;
extern MovingPathAnimation* moveRBall2;
extern MovingPathAnimation* SnakeLeft;
extern MovingPathAnimation* SnakeRight;
extern MovingPathAnimation* SnakeDown;
extern MovingPathAnimation* SnakeUp;

extern MovingPathAnimation* fallingRight;
extern MovingPathAnimation* fallingLeft;
extern MovingPathAnimation* fallingDownLeft;
extern MovingPathAnimation* fallingDownRight;
extern MovingPathAnimation* SnakeFallLeft;
extern MovingPathAnimation* SnakeFallRight;



extern MovingPathAnimation* fallRightBall1;
extern MovingPathAnimation* fallRightBall2;
extern MovingPathAnimation* fallDownBall2;
extern MovingPathAnimation* fallDownBall1;

extern MovingPathAnimation* SnakeBallRight;
extern MovingPathAnimation* SnakeBallLeft;


void initMoves() {
	int iterate;
	
	//right
	ifstream rightI("JSONS/Moves/right.json");
	json j;
	rightI >> j;
	vector<PathEntry> path;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		//entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 2;
		entry->dx = j["list"][iterate]["dx"].get<int>();
		entry->dy = j["list"][iterate]["dy"].get<int>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	animid_t t = 1;
	rightMove = new MovingPathAnimation(path, t);
	path.clear();
	
	//up
	ifstream upI("JSONS/Moves/up.json");
	upI >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		//entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 2;
		entry->dx = j["list"][iterate]["dx"].get<int>();
		entry->dy = j["list"][iterate]["dy"].get<int>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	t++;
	upMove = new MovingPathAnimation(path, t);
	path.clear();

	//left
	ifstream leftI("JSONS/Moves/left.json");
	leftI >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		//entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 2;
		entry->dx = j["list"][iterate]["dx"].get<int>();
		entry->dy = j["list"][iterate]["dy"].get<int>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	t++;
	leftMove = new MovingPathAnimation(path, t);
	path.clear();


	//down
	ifstream downI("JSONS/Moves/down.json");
	downI >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		//entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 2;
		entry->dx = j["list"][iterate]["dx"].get<int>();
		entry->dy = j["list"][iterate]["dy"].get<int>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	t++;
	downMove = new MovingPathAnimation(path, t);
	path.clear();



	//circle
	ifstream circle("JSONS/Moves/circle.json");
	circle >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 6;
		entry->dx = j["list"][iterate]["dx"].get<int>();
		entry->dy = j["list"][iterate]["dy"].get<int>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	t++;
	circleAnimation1 = new MovingPathAnimation(path, t);
	t = 5;
	circleAnimation2 = new MovingPathAnimation(path,t );
	path.clear();


	//circle up left 
	ifstream circleup("JSONS/Moves/circleupleft.json");
	circleup >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 6;
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	
	t++;

	//circle up right
	circleUpLeft = new MovingPathAnimation(path, t);
	path.clear();


	//circle up 
	ifstream circlerightup("JSONS/Moves/circleupright.json");
	circlerightup >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 6;
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	circleUpRight = new MovingPathAnimation(path, t);
	path.clear();


	//left teleport
	ifstream lefttele("JSONS/Moves/leftteleport.json");
	lefttele >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 6;
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	leftTeleport = new MovingPathAnimation(path, t);
	path.clear();

	ifstream righttele("JSONS/Moves/rightteleport.json");
	righttele >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->delay = 6;
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	rightTeleport = new MovingPathAnimation(path, t);
	path.clear();


	//moveleftball
	ifstream moveBal("JSONS/Moves/moveBall.json");
	moveBal >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	moveBall1 = new MovingPathAnimation(path, t);
	path.clear();


	//moveleftball
	ifstream moveBal2("JSONS/Moves/moveBall.json");
	moveBal2 >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	moveBall2 = new MovingPathAnimation(path, t);
	path.clear();

	//moveRightball1
	ifstream moveRBal("JSONS/Moves/moveRBall.json");
	moveRBal >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	moveRBall1 = new MovingPathAnimation(path, t);
	path.clear();


	//moveRightball
	ifstream moveRBal2("JSONS/Moves/moveRBall.json");
	moveRBal2 >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	moveRBall2 = new MovingPathAnimation(path, t);
	path.clear();

	//fallRightBall
	//////////
	////////////
	///////////
	ifstream fallRightBal1("JSONS/Moves/fallRightBall.json");
	fallRightBal1 >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->frame = 0;
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	t++;
	fallRightBall1 = new MovingPathAnimation(path, t);
	path.clear();


	ifstream fallRightBal2("JSONS/Moves/fallRightBall.json");
	fallRightBal2 >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->frame = 0;
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	t++;
	fallRightBall2 = new MovingPathAnimation(path, t);
	path.clear();

	//falldownBall
	//////////
	////////////
	///////////
	ifstream falldownBal1("JSONS/Moves/fallDownBall.json");
	falldownBal1 >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->frame = 0;
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	t++;
	fallDownBall1 = new MovingPathAnimation(path, t);
	path.clear();


	ifstream falldownBal2("JSONS/Moves/fallDownBall.json");
	falldownBal2 >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->frame = 0;
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}
	t++;
	fallDownBall2 = new MovingPathAnimation(path, t);
	path.clear();

	//

	////////////////////
	////////////////////
	//////////////////
	/////////////////
	///////////////////

	//fallingRight
	ifstream rightfall("JSONS/Moves/fallingRight.json");
	rightfall >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	fallingRight = new MovingPathAnimation(path, t);
	path.clear();



	//fallingLeft
	ifstream leftfall("JSONS/Moves/fallingLeft.json");
	leftfall >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	fallingLeft = new MovingPathAnimation(path, t);
	path.clear();




	//fallingDownLeft
	ifstream downleftfall("JSONS/Moves/fallingDownLeft.json");
	downleftfall >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	fallingDownLeft = new MovingPathAnimation(path, t);
	path.clear();


	//fallingDownRight
	ifstream downrightfall("JSONS/Moves/fallingDownRight.json");
	downrightfall >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	fallingDownRight = new MovingPathAnimation(path, t);
	path.clear();



	//snakeRight
	ifstream snakeright("JSONS/Moves/SnakeRight.json");
	snakeright >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	SnakeRight = new MovingPathAnimation(path, t);
	path.clear();

	//snakeLeft
	ifstream snakeleft("JSONS/Moves/SnakeLeft.json");
	snakeleft >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	SnakeLeft = new MovingPathAnimation(path, t);
	path.clear();

	//snakeDown
	ifstream snakedown("JSONS/Moves/SnakeDown.json");
	snakedown >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	SnakeDown = new MovingPathAnimation(path, t);
	path.clear();

	//snakeUp
	ifstream snakeup("JSONS/Moves/SnakeUp.json");
	snakeup >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	SnakeUp = new MovingPathAnimation(path, t);
	path.clear();

	//snakeBallRight
	ifstream snakeballright("JSONS/Moves/SnakeBallRight.json");
	snakeballright >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	SnakeBallRight = new MovingPathAnimation(path, t);
	path.clear();

	//snakeBallLeft
	ifstream snakeballleft("JSONS/Moves/SnakeBallLeft.json");
	snakeballleft >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	SnakeBallLeft = new MovingPathAnimation(path, t);
	path.clear();




	//fallLeftBall
	ifstream fallleftsnake("JSONS/Moves/fallLeftSnake.json");
	fallleftsnake >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	SnakeFallLeft = new MovingPathAnimation(path, t);
	path.clear();

	//fallLeftBall
	ifstream fallrightsnake("JSONS/Moves/fallRightSnake.json");
	fallrightsnake >> j;
	for (iterate = 0; iterate < j["MovingPathAnimatornum"].get<int>(); iterate++) {
		PathEntry *entry = new PathEntry();
		entry->delay = j["list"][iterate]["delay"].get<int>();
		entry->dx = j["list"][iterate]["dx"].get<float>();
		entry->dy = j["list"][iterate]["dy"].get<float>();
		entry->frame = j["list"][iterate]["frame"].get<int>();
		entry->pos = j["list"][iterate]["pos"].get<int>();
		path.push_back(*entry);
	}

	t++;
	SnakeFallRight = new MovingPathAnimation(path, t);
	path.clear();


}


