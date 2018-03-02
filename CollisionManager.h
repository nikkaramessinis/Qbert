#include "Sprite.h"
#include "QBERT.h"
#include "Artificial_Intelligence.h"

#pragma once
class CollisionManager
{
	/*--- ODHGIES ---*/
	/* Ftiaxnoume ena instance afths ths klashs sth main. otan ftiaxtei to sprite qbert to kanoume
	add edw mesa. kathe fora pou ftiaxnete ena bot to kanoume add episis edw mesa. otan xanete to diagrafoume.
	kaloume thn collisionCheck() sto gameloop ths main. o kwdikas mesa sthn collisionHandle() einai aftos poy
	tha diaxiristei ti tha ginei otan ginei colission qbert me bot*/

private:

	// Epistrefei true ean to sprite1 exei colllision me to sprite2
	bool spritesAreCollided(Sprite *sprite1, Sprite *sprite2);

	//Kaleitai kai Diaxirizete thn katastash otan simvei to collision (p.x life = life-1 kai ksana apo tn arxh)
	void collisionHandle();

public:

	Artificial_Intelligence * ai;

	//H sigkekrimenh arxitektonikh panta tha elegxei ton qbert me ta ipolipa
	QBERT * qbertClassObject;
	Sprite * Qbert;

	//pinakas me ta sprites olwn ton bots pou mporoun na sigkroustoun me ton qbert
	//oi sinartiseis gia afta parexontai parakatw
	vector<Sprite*> bots;

	//afth h synarthsh tha kaleitai sto gameloop ths main
	bool collisionCheck();

	void addBot(Sprite *bot);
	int removeBot(Sprite *bot); //1 an yparxei 0 an oxi
	void addQbert(Sprite *qbert);
	int removeQbert(Sprite *qbert); //1 an yparxei 0 an oxi
	void setQbertClassObject(QBERT *qbert);

	CollisionManager();
	~CollisionManager();
};

