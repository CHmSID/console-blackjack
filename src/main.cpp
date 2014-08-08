#include "player.hpp"
#include "deck.hpp"
#include <stdio.h>
#include <iostream>

using std::string;
using std::cin;

int main() {

    bool quitGame = false;
    string userLine;

    printf("Welcome to Blackjack!\n\n");

    Deck deck;
    deck.setNewDeck();

    //DEBUG
    printf("Deck set, %d cards in deck:\n", deck.getSize());
    deck.printDeck();
    printf("Shuffling...\n\n");
    deck.shuffle();
    deck.printDeck();
    //END DEBUG

    Player player;
    player.giveCard();

    printf("The game begins\n");

    while(!quitGame) {

        cin >> userLine;

        if(userLine=="quit" || userLine=="exit")
            quitGame = true;
    }

    return 0;
}

/* one more thing , you should use assert() and static_assert() to enforce 
   class invariants and pre-conditions, and post-conditions*/