/*
Author: Jerzy Baran
*/
#ifndef DECK_H
#define DECK_H
#include "card.hpp"
#include <vector>

using std::vector;

class Deck {

public:

    void setNewDeck();  //puts all cards back into the deck
            //only use together with Player.emptyHand()
            //to avoid duplicate cards in player's hand
    void shuffle();     //pretty self-explanatory
    void printDeck();   //Debug procedure
    int getSize()const; //how many cards in the deck

    vector<Card>* getDeck();    //this returns a pointer to variable 'deck'
                                //it allows me to use deck's methods
                                //from different classes

private:
    vector<Card> deck;
};

#endif