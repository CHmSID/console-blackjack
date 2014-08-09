#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"
#include "deck.hpp"
#include <vector>

using std::vector;

class Player {

public:
	Player();
	~Player();

	void giveCard(Deck& deck);	//when the players says 'hit', he get's another card
	void emptyHand();	//when the player says 'stand' or
						//goes over 21, deletes all cards in player's hand
	int getPoints();	//when the player says 'stand'
	void printHand();

protected:
	vector<Card> playerHand;
};

#endif