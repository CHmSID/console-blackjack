/*
Author: Jerzy Baran
*/
#include "deck.hpp"
#include <stdio.h>
#include <vector>
#include <algorithm>    //random_shuffle

using std::vector;
using std::random_shuffle;

void Deck::setNewDeck() {

    //wipe the old deck
    deck.erase(deck.begin(), deck.begin() + deck.size());

    //and add new cards
    for(int i = 0; i < 4; i++) {        //suits

        for(int k = 0; k < 13; k++) {   //values

            deck.push_back(Card(k, i));
        }
    }
}

void Deck::shuffle() {

    //the second parameter could probably be 'deck.end()'
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

//returns a pointer to vector<Card>
vector<Card>* Deck::getDeck(){

    //address of deck
    return &deck;
}