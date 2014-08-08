#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "card.h"

class Player {

public:
	Player();
	~Player();

	void giveCard();	//when the players says 'hit', he get's another card
	void emptyHand();	//when the player says 'stand' or
						//goes over 21, deletes all cards in player's hand
	int getPoints();	//when the player says 'stand'
	void printHand();

private:
	std::vector<Card> playerHand;
};

#endif