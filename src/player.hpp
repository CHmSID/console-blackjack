#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"
#include "deck.hpp"
#include <vector>

using std::vector;

class Player {

public:

	void giveCard(Deck& deck);	//when the players says 'hit', he get's another card
                                //from the deck, ie: that card is removed from the deck
	void emptyHand();	//when the player says 'stand' or
						//goes over 21, removes all cards from player's hand
	int getPoints();	//used in various situations, 
                        //especially when the player says 'stand'
	void printHand();   //shows player's points and his cards

protected:  //since Dealer will inherit from this class, and he'll need direct access
            //to playerHand
	vector<Card> playerHand;   //a container for objects of type Card
};

#endif