#pragma once
#include "QBERT.h"
#include "Snake.h"
#include "Ball.h"
#include <ctime>
#include "AnimatorHolder.h"
#include "SoundManager.h"
#include "AnimationFilmHolder.h"
#include "IsometricPyramid.h"
extern IsometricPyramid * Pyramid;
extern MovingPathAnimation* SnakeRight;
extern MovingPathAnimation* SnakeDown;
extern MovingPathAnimation* SnakeBallRight;
extern MovingPathAnimation* SnakeBallLeft;
extern bool snakeFlag;

extern int sphere_flag;
extern int counter2;
extern bool snakefell;

class Artificial_Intelligence
{
private:

	QBERT * Qbert;
	Snake *snake;
	Ball *Ball1,*Ball2;

	long double currentSecond;
	long double AIstartTime;

	//balls
	long double secondsToSpawnBall;
	long double secondsToMoveBall;
	long double secondsToMoveBall2;
	long double secondsToWaitBall;
	int ballsAlive;

	//snake
	long double secondsToSpawnSnake;
	long double secondsToMoveSnake;
	long double nextTimeToSpawnSnake; // gia otan pethanei to snake na ksanaginei spawn
	bool snakeIsAlive;
	int qbertLastX;
	int qbertLastY;
	bool snakeIsBall;

	//gia to spawn, generation
	void spawnSnake();
	void spawnBall(Ball *ball);

	//gia to moving
	//void moveBalls();
	bool moveBallByTime(Ball *Ball,timestamp_t timestamp);
	bool moveSnakeByTime(Snake *snake, timestamp_t timestamp);
	bool moveSnake(Snake *snake, timestamp_t timestamp);
	bool moveSnakeBallByTime(Snake *snake, timestamp_t);

	bool testDone = false;

public:

	bool ball1AnimHasFinished;
	bool ball2AnimHasFinished;

	bool run(timestamp_t timestamp);
	long double getCurrentSecond();
	void generateBotsByTime();
	
	//otan to snake pethanei sto game prepei na kalesoume afth ti sinartisi wste na ksanaginei spawn meta apo 15 seconds
	void killSnake();
	
	void setQbert(QBERT* qbert);
	void setSnake(Snake *snake);
	void setBall1(Ball *ball);
	void setBall2(Ball *ball);


	Artificial_Intelligence();
	~Artificial_Intelligence();
	void startBotsFromBeginning();
};

