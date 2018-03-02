#include "CollisionManager.h"
#include "Sprite.h"
#include "Artificial_Intelligence.h"






CollisionManager::CollisionManager()
{
}

void CollisionManager::addBot(Sprite *bot) {
	bots.push_back(bot);
}

int CollisionManager::removeBot(Sprite *bot) {

	//iterator psaxnei na vrei to index tou sigkekrimenou bot
	vector<Sprite*>::iterator position = find(bots.begin(), bots.end(), bot);

	if (position != bots.end()) { //ean vrethike
		bots.erase(position);
		return 1;
	}
	else {
		return 0; //den vrethike
	}
		
}

void CollisionManager::addQbert(Sprite *qbert) {
	Qbert = qbert;
}

int CollisionManager::removeQbert(Sprite *qbert) {

	if (Qbert != NULL) {

		Qbert = NULL;
		return 1;

	}
	else {
		return 0;
	}

}

void CollisionManager::setQbertClassObject(QBERT * qbert)
{
	qbertClassObject = qbert;
}

bool CollisionManager::spritesAreCollided(Sprite *sprite1, Sprite *sprite2) {

	//efarmozoume geometria orthogwniwn me boxes pros to parwn

	if (sprite1->getCenterX() < sprite2->getX1() ||
		sprite2->getX2() < sprite1->getCenterX() ||
		sprite1->getCenterY() < sprite2->getY1() ||
		sprite2->getY2() < sprite1->getCenterY()) {

		return false;

	}
	else {
		return true;
	}

}

bool CollisionManager::collisionCheck(){

	//return false;

	if (qbertClassObject->collisionSensitive == false) return false;

	//gia ola ta bots poy yparxoun afth th stigmh
	for (size_t  i = 0; i < bots.size();i++) {

		//an o qbert sigkrouete me kapoio
		if (spritesAreCollided(Qbert, bots[i])) {
			collisionHandle(); //diaxirisou to collision
			return true;
		}

	}
	return false;
}

void CollisionManager :: collisionHandle() {
	ai->startBotsFromBeginning();
	qbertClassObject->setLife(qbertClassObject->getLife() - 1); //decrement kata 1
}


CollisionManager::~CollisionManager()
{
}
