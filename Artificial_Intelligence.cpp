#include "Artificial_Intelligence.h"
#include "Cube.h"

Artificial_Intelligence::Artificial_Intelligence()
{
	//ball
	secondsToSpawnBall = 3; //edw vazoume to ana posa seconds theloume na ginei spawn h mpala
	secondsToMoveBall = 1.1;
	secondsToMoveBall2 = 1;
	secondsToWaitBall = 0.5;

	Ball1 = NULL;
	Ball2 = NULL;
	ballsAlive = 0;

	//snake
	secondsToSpawnSnake = 5; //edw vazoume to meta apo posa seconds theloume na ginei spawn to snake
	nextTimeToSpawnSnake = secondsToSpawnSnake;
	secondsToMoveSnake = 1.2;
	snake = NULL;
	snakeIsAlive = false ;

	snakeIsBall = 1;


}



bool Artificial_Intelligence::run(timestamp_t timestamp) {

	bool draw = false;
	currentSecond = (long double)al_get_time();
	generateBotsByTime();

	draw = moveBallByTime(Ball1, timestamp);

	draw = moveBallByTime(Ball2, timestamp);

	draw = moveSnake(snake,timestamp);

	if (currentSecond == 20 && !testDone) {
		killSnake();
		testDone = true;
	}

	return draw;

}

long double Artificial_Intelligence::getCurrentSecond() {
	return currentSecond;
}

//int Artificial_Intelligence::setStartingTime() {
	//startingSecond = (int)al_get_time();
	//return startingSecond;
//}

void Artificial_Intelligence::generateBotsByTime() {

	if (currentSecond - AIstartTime > (ballsAlive + 1)*secondsToSpawnBall) {
		if(!Ball1->isAlive)spawnBall(Ball1);
		else if(!Ball2->isAlive) spawnBall(Ball2);
	}

	if ((currentSecond - AIstartTime > nextTimeToSpawnSnake) && !snakeIsAlive) {
		spawnSnake();
	}


}

void Artificial_Intelligence::spawnSnake() {
	snakeIsAlive = true;
	counter2 = 0;

	//testttt kati allo tha to kinei logika o animator
	snake->GetSprite()->SetVisibility(true);
	/*snake->GetSprite()->setX1(383);
	snake->GetSprite()->setY1(103);*/

	//snake->GetSprite()->setX1(415);
	//snake->GetSprite()->setY1(151);
	snake->GetSprite()->setX1(415);
	snake->GetSprite()->setY1(181);
	
	snake->setCubeX(2);
	snake->setCubeY(2);


	snake->snakeBornAt = al_get_time();
	snake->movesAsBall = 0;
	snakeIsBall = true;

	//bala
	snake->ChangeAnimation(SnakeBallLeft, SnakeBallRight);
	//snake->ChangeSprite(AnimationFilmHolder::Get().GetFilm("snakeBall"));
	snake->changeToBall();

	snakeFlag = false;

	//snake->Display();
}

void Artificial_Intelligence::spawnBall(Ball *ball) {
	
	if (Ball1->isAlive && Ball2->isAlive) {


		ballsAlive++; //steps
	}


	if (ball->getAnimator()->HasFinished()) {
		ball->canSpawn = true;
	}

	if (!ball->canSpawn) return;


	ballsAlive++;

	ball->movesFromLastSpawn = 0;
	ball->isAlive = true;
	ball->GetSprite()->SetVisibility(true);
	ball->GetSprite()->SetFrame(1);

	//deksia h aristera stn 2h seira
	if (ball == Ball1) {
		ball->GetSprite()->setX1(351);
		ball->GetSprite()->setY1(183);
	}
	else {
		ball->GetSprite()->setX1(415);
		ball->GetSprite()->setY1(183);
	}

	ball->ballBornAt = al_get_time();

}

void Artificial_Intelligence:: killSnake() {


	counter2 = 0;
	snakeIsAlive = false;
	nextTimeToSpawnSnake = currentSecond + secondsToSpawnSnake;
	snakeFlag = true;


}

bool Artificial_Intelligence::moveSnake(Snake *snake,timestamp_t timestamp) {

	if (snakeIsBall) {
		moveSnakeBallByTime(snake, timestamp);
	}
	else {
		moveSnakeByTime(snake, timestamp);
	}
	return true;
}

bool Artificial_Intelligence::moveSnakeBallByTime(Snake *snake,timestamp_t timestamp) {
	if (currentSecond > (snake->getTotalMoves() + 1)*secondsToMoveSnake) {

		//an molis tr genithike mn kounisis
		if (snake->snakeBornAt + secondsToMoveSnake> currentSecond) {
			snake->setTotalMoves(snake->getTotalMoves() + 1);
			return false;
		}

		if (snake->movesAsBall == 5) {
			snake->GetSprite()->setY1(400);
			//snake->ChangeSprite(AnimationFilmHolder::Get().GetFilm("snake"));
			snake->changeToSnake();

			snake->ballSnakeSprite->setX1(1);
			snake->ballSnakeSprite->setY1(1);

			snake->ChangeAnimation(SnakeDown, SnakeRight);
			snakeIsBall = false; // kai sto epomeno loop kaleite i move snake ;)

			return true;
		}
		int direction = 0;

		//initialize random seed
		srand(time(0));
		direction = rand() % 2;

		if (snakeIsAlive) {
			if (direction == 0) {
				//left
				/*AnimatorHolder::Get().MarkAsRunning(Ball->getAnimator());
				*/
				//Ball->getAnimator()->Start(Ball->GetSprite(), Ball->getLAnimation(), timestamp);
				
				//snake->GetSprite()->Move(-32, 48);
				snake->moveDown(timestamp);
				//to x paramenei idio to y katevenei 1
				/*snake->setCubeY(snake->getCubeX() + 1);*/

		
			}
			else {
				//right
				/*AnimatorHolder::Get().MarkAsRunning(Ball->getAnimator());
				*/
				//Ball->getAnimator()->Start(Ball->GetSprite(), Ball->getRAnimation(), timestamp);
				//snake->GetSprite()->Move(32, 48);
				snake->moveRight(timestamp);

				//to x katevenei 1  to y katevenei 1
				/*snake->setCubeY(snake->getCubeY() + 1);
				snake->setCubeX(snake->getCubeX() + 1);*/

		
			}
		}
		//al_clear_to_color(al_map_rgb(0, 0, 0));
		//Ball->Display();
		if (snakeIsAlive) {
			snake->movesAsBall++;
			SoundManager::playBallJump();
		}
		snake->setTotalMoves(snake->getTotalMoves() + 1);

		return true; //gia draw
	}
	return false; //gia draw
}

bool Artificial_Intelligence::moveSnakeByTime(Snake *snake,timestamp_t timestamp) {
	
	//ean exei perasei perissoteros i isos xronos
	// anamesa stn teleftea fora pou kinithike kai ton
	//xrono p orisame na kinithei
	if (currentSecond > (snake->getTotalMoves() + 1)*secondsToMoveSnake) {

		if (!snakeIsAlive) {
			//ksana to metrame gia ton xronismo
			snake->setTotalMoves(snake->getTotalMoves() + 1); //afksisi kata 1
			return false;
		}




		IsoCube*temp;
		temp = Pyramid->SearchById(snake->getCubeY(), snake->getCubeX());

		int x = snake->getCubeX();
		int y = snake->getCubeY();

		if (sphere_flag != -1) {
			

			if (x==y) 
			{
			
			}
			else if(x==1)
			{
			
			}
		
		}

		if (sphere_flag == 0) {
			//einai aristera

			if (x == 1 && y == 5) {

				snakefell = true;
				snake->fallRight(timestamp);
				snake->setTotalMoves(snake->getTotalMoves() + 1);

				killSnake();

				//snake->moveLeft(timestamp);
			}
			else if (y > 5) {

				if (x == 1) {
					snake->moveUp(timestamp);
				}
				else {
					snake->moveLeft(timestamp);
				}

				
			}
			else if (y <= 5) {

				snake->moveDown(timestamp);
			}



			snake->setTotalMoves(snake->getTotalMoves() + 1);
			return true;
		}
		else if (sphere_flag == 1) {

			if (x == 5 && y == 5) {

				snakefell = true;
				snake->fallLeft(timestamp);
				snake->setTotalMoves(snake->getTotalMoves() + 1);
				//snakeIsAlive = false;

				killSnake();

				//snake->moveUp(timestamp);
			}
			else if (y > 5) {

				if (x == 6) {
					snake->moveLeft(timestamp);
				}
				else {
					snake->moveUp(timestamp);
				}

				
			}
			else if (y <= 5) {

				snake->moveRight(timestamp);
			}

			//einai deksia
			//snake->moveUp(timestamp);

			snake->setTotalMoves(snake->getTotalMoves() + 1);
			return true;

		}



		//an to snake einai apo panw
		if (snake->getCubeY() < Qbert->getCubeY()) {

			//an einai apo aristera
			if (snake->GetSprite()->getX1() < Qbert->GetSprite()->getX2()) {

				//an einai akrivos apo panw  h parapanw seira
				if (snake->getCubeY() + 2 == Qbert->getCubeY() ) {
					snake->moveDown(timestamp);
				}
				else {
					
					snake->moveRight(timestamp);
				}

			}
			else {
				//an einai apo deksia

				//an einai akrivos apo panw  h parapanw seira
				if ((snake->getCubeY() + 2 == Qbert->getCubeY() || snake->getCubeY() + 1 == Qbert->getCubeY())
					&& snake->getCubeX()!=1) {  // kai den einai sto terma aristera kivo ;)
					snake->moveLeft(timestamp);
				}
				else {

					snake->moveDown(timestamp);
				}

			}

		}
		//an to snake einai apo katw
		//-1 big story
		else if (snake->getCubeY() > Qbert->getCubeY()) {

			//an einai apo aristera
			if (snake->GetSprite()->getX1() < Qbert->GetSprite()->getX2()) {
				//pata up
				//snake->moveUp();

				//an einai akrivos apo katw  h parakatw seira
				if (snake->getCubeY() - 1 == Qbert->getCubeY() || snake->getCubeY() - 2 == Qbert->getCubeY()) {
					snake->moveUp(timestamp);
				}
				else {
					//allios an einai dipla tou pigene apo panw
					snake->moveUp(timestamp);
				}

			}
			else {
				//an einai apo deksia

				//an einai parakatw  h paraparakatw seira  big story
				if (snake->getCubeY() - 2 == Qbert->getCubeY() || snake->getCubeY() - 1 == Qbert->getCubeY()) {
					snake->moveLeft(timestamp);
				}
				else {
					//allios an einai dipla tou pigene apo panw
					snake->moveLeft(timestamp);
				}

				//pata left  !!!!!!!!!!!!!!!!!! // i
				//snake->moveLeft();

			}


		}
		//an to snake einai sthn idia seira
		else {

			//an einai apo aristera
			if (snake->GetSprite()->getX1() < Qbert->GetSprite()->getX2()) {

				//an einai teleftea seira
				if (snake->getCubeY() == 7) {
					//pata up
					snake->moveUp(timestamp);
				}
				else {
					//pata up
					snake->moveRight(timestamp);
				}

			}
			else {
				//an einai apo deksia

				//an einai teleftea seira
				if (snake->getCubeY() == 7) {
					//pata left
					snake->moveLeft(timestamp);
				}
				else {
					//pata down
					snake->moveLeft(timestamp);

				}

			}
			
			
		}
		snake->setTotalMoves(snake->getTotalMoves() + 1); //afksisi kata 1


		return true; //egine allagh
		
	}
	return false; // den egine allagh
}

bool Artificial_Intelligence::moveBallByTime(Ball *Ball,timestamp_t timestamp){
	
	//ean exei perasei perissoteros i isos xronos
	// anamesa stn teleftea fora pou kinithike kai ton
	//xrono p orisame na kinithei

	//ean den zei min kaneis kati
	//if (!Ball->isAlive) return false;
	int randhash = 0;
	if (Ball == Ball1) {
		randhash = 123145;
	}
	else {
		randhash = 8764578;
	}

	long double secondsToMove;

	int direction = 0;

	//initialize random seed
	srand(time(0)*randhash);

	direction = rand() % 2;


	if (currentSecond > (Ball->ballTotalMoves + 1)*secondsToMoveBall) {
		
		//an molis tr genithike mn kounisis
		if (((Ball->ballBornAt + secondsToWaitBall)> currentSecond) && (Ball->movesFromLastSpawn == 0)) {

			Ball->ballTotalMoves++;
			return false;
		}

		if (!Ball->isAlive) {
			Ball->ballTotalMoves++;
			return false;
		}

		

		if (Ball->movesFromLastSpawn == 5) {
			//ean exei kanei 5 tha einai sto keno opote thn rixnoume kai kanoume return

			


			Ball->movesFromLastSpawn = 0;
			Ball->isAlive = false;
			//Ball->GetSprite()->SetVisibility(false);
			if (direction == 0) {
				Ball->fallLeft(timestamp);
			}
			else {
				Ball->fallRight(timestamp);
			}

			Ball->ballTotalMoves++;

			//AnimatorHolder::Get().MarkAsSuspended(Ball->getAnimator());

			return true;
		}

		Ball->canSpawn = false;
		
		

		if (direction == 0) {
			//left
			//Ball->GetSprite()->Move(-32, 48);
			AnimatorHolder::Get().MarkAsRunning(Ball->getAnimator());
			Ball->getAnimator()->Start(Ball->GetSprite(), Ball->getLAnimation(), timestamp);
		}
		else {
			//right
			AnimatorHolder::Get().MarkAsRunning(Ball->getAnimator());
			Ball->getAnimator()->Start(Ball->GetSprite(), Ball->getRAnimation(), timestamp);
		}
		//al_clear_to_color(al_map_rgb(0, 0, 0));
		//Ball->Display();
		if (Ball->isAlive) { 
			Ball->movesFromLastSpawn++; 
			SoundManager::playBallJump();
		}
		Ball->ballTotalMoves++;



		return true; //gia draw
	}

	return false; //gia draw

	

}

//void Artificial_Intelligence::moveSnake(){}


void Artificial_Intelligence::setQbert(QBERT* qbert) {
	Qbert = qbert;
}
void Artificial_Intelligence::setBall1(Ball *ball) {
	Ball1 = ball;
}
void Artificial_Intelligence::setBall2(Ball *ball) {
	Ball2 = ball;
}

void Artificial_Intelligence::setSnake(Snake* snake) {
	Artificial_Intelligence::snake = snake;
}

Artificial_Intelligence::~Artificial_Intelligence()
{
	
}

void Artificial_Intelligence::startBotsFromBeginning() {
	bool draw = false;

	/*killSnake();*/

	//restart twn balls
	//secondsToSpawnBall += (long double)al_get_time(); // an einai 3 px kai o xronos mas stamatei sto 500 tote sto 503 tha ksanavgei
	//ballsAlive = 0;
	Ball1->isAlive = false;
	Ball2->isAlive = false;
	Ball1->GetSprite()->SetVisibility(false);
	Ball2->GetSprite()->SetVisibility(false);
	Ball1->GetSprite()->setX1(1);
	Ball1->GetSprite()->setY1(1);
	Ball2->GetSprite()->setX1(1);
	Ball2->GetSprite()->setY1(1);
	Ball1->canSpawn = true;
	Ball2->canSpawn = true;

	//restart tou snake
	//secondsToSpawnSnake += (long double)al_get_time();
	nextTimeToSpawnSnake = secondsToSpawnSnake;
	snakeIsAlive = false;

	snake->GetSprite()->setX1(1);
	snake->GetSprite()->setY1(1);
	snake->ballSnakeSprite->setX1(1);
	snake->ballSnakeSprite->setY1(1);
	snake->snakeBodySprite->setX1(1);
	snake->snakeBodySprite->setY1(1);

	snakeIsBall = true;
	snake->movesAsBall = 0;

	Qbert->collisionSensitive = true;

	//bala
	snake->ChangeAnimation(SnakeBallLeft, SnakeBallRight);
	//snake->ChangeSprite(AnimationFilmHolder::Get().GetFilm("snakeBall"));
	snake->changeToBall();
	snake->GetSprite()->SetVisibility(false);
	//collisionManager.addBot(Ball1->GetSprite()); //!! addBot kalw edw
	//o neos starting xronos tou AI 

	ballsAlive = 0;


	AIstartTime = al_get_time();
	//
}
