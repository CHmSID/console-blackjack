#include "deck.hpp"
#include <stdio.h>
#include <algorithm>    //for shuffling

// Deck::Deck() {

// }

// Deck::~Deck() {

// }

using std::random_shuffle;

void Deck::setNewDeck() {

    deck.erase(deck.begin(), deck.begin() + deck.size());

    for(int i = 0; i < 4; i++) {        //suits

        for(int k = 0; k < 13; k++) {   //values

            deck.push_back(Card(k, i));
        }
    }
}

void Deck::shuffle() {

    random_shuffle(deck.begin(), deck.begin() + deck.size());
}

void Deck::printDeck() {

    for(int i = 0; i < deck.size(); i++) {

        printf("%s of %s\n",
            deck.at(i).getVerboseValue(), deck.at(i).getSuit());
    }
}

int Deck::getSize()const{

    return deck.size();
}