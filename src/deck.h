#ifndef DECK_H
#define DECK_H
#include <vector>
#include "card.h"

class Deck {

public:
	Deck();
	~Deck();

	void setNewDeck();	//puts all cards back into the deck
						//only use together with Player.emptyHand()
						//to avoid duplicate cards
	void shuffleDeck();

private:
	std::vector<Card> deck;
};

#endif