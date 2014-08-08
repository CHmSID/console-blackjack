#ifndef DECK_H
#define DECK_H
#include "card.hpp"
#include <vector>

using std::vector;

class Deck {

public:
    // Deck();
    // ~Deck();

    void setNewDeck();  //puts all cards back into the deck
            //only use together with Player.emptyHand()
            //to avoid duplicate cards
    void shuffle();
    void printDeck();   //Debug procedure
    int getSize()const;

    vector<Card>* getDeck();

private:
    vector<Card> deck;
};

#endif