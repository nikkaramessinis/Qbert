#include "SoundManager.h"
#include <allegro5\allegro_audio.h>

	//prepei na dilonoume tis static mas
  ALLEGRO_SAMPLE* SoundManager::snakeJumpSound;
  ALLEGRO_SAMPLE* SoundManager::qbertJumpSound;
  ALLEGRO_SAMPLE* SoundManager::ballJumpSound;
  ALLEGRO_SAMPLE* SoundManager::gameStart;
  ALLEGRO_SAMPLE* SoundManager::qbertLost;
  ALLEGRO_SAMPLE* SoundManager::qbertByeBye;
  ALLEGRO_SAMPLE* SoundManager::diskRide;
  ALLEGRO_SAMPLE* SoundManager::qbertFalling;
  ALLEGRO_SAMPLE* SoundManager::coinInsert;

SoundManager::SoundManager()
{
	al_install_audio();

	qbertJumpSound = al_load_sample("Resources/sounds/Hop.wav");
	snakeJumpSound = al_load_sample("Resources/sounds/Ahop.wav");
	ballJumpSound = al_load_sample("Resources/sounds/bonk.wav");
	qbertByeBye = al_load_sample("Resources/sounds/byebye.wav");
	qbertLost = al_load_sample("Resources/sounds/Sware1.wav");
	diskRide = al_load_sample("Resources/sounds/RideTheDisk.wav");
	gameStart = al_load_sample("Resources/sounds/GameStartMusic.wav");
	qbertFalling = al_load_sample("Resources/sounds/CoilyOverTheEdge.wav");
	coinInsert = al_load_sample("Resources/sounds/coinDrop.wav");
	al_reserve_samples(9); // pros to paron 9
}


SoundManager::~SoundManager()
{
}

void SoundManager::QbertBye()
{
	al_play_sample(qbertByeBye, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}

void SoundManager::Qbertdie()
{
	al_play_sample(qbertLost, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}

void SoundManager::playQbertJump()
{
	al_play_sample(qbertJumpSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}

void SoundManager::playBallJump()
{
	al_play_sample(ballJumpSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}

 void  SoundManager::playSnakeJump()
{
	al_play_sample(snakeJumpSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

}

 void SoundManager::playDiskRide()
 {
	 al_play_sample(diskRide, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
 }

 void SoundManager::playGameStart()
 {
	 al_play_sample(gameStart, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
 }

 void SoundManager::playQbertFalling()
 {
	 al_play_sample(qbertFalling, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
 }

 void SoundManager::playInsertCoin()
 {
	 al_play_sample(coinInsert, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
 }

 