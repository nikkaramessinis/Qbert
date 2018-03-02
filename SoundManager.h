#pragma once
#include <allegro5\allegro_audio.h>
class SoundManager
{
private:

	static ALLEGRO_SAMPLE *qbertJumpSound;
	static ALLEGRO_SAMPLE *ballJumpSound;
	static ALLEGRO_SAMPLE *snakeJumpSound;
	static ALLEGRO_SAMPLE *gameStart;
	static ALLEGRO_SAMPLE *qbertLost;
	static ALLEGRO_SAMPLE *qbertByeBye;
	static ALLEGRO_SAMPLE *diskRide;
	static ALLEGRO_SAMPLE *qbertFalling;
	static ALLEGRO_SAMPLE *coinInsert;

public:
	SoundManager();
	~SoundManager();

	static void QbertBye();
	static void Qbertdie();
	static void playQbertJump();
	static void playBallJump();
	static void playSnakeJump();
	static void playDiskRide();
	static void playGameStart();
	static void playQbertFalling();
	static void playInsertCoin();
	
};

