#include "player.hpp"
#include "deck.hpp"
#include <stdio.h>
#include <iostream>

using std::string;
using std::cin;

int main() {

    bool quitGame = false;
    string userLine;

    printf("Welcome to Blackjack!\n");
    printf("Type 'help' for instructions\n\n");

    Deck deck;
    deck.setNewDeck();

    // //DEBUG
    // printf("Deck set, %d cards in deck:\n", deck.getSize());
    // deck.printDeck();
    // printf("Shuffling...\n\n");
    // deck.shuffle();
    // deck.printDeck();
    // //END DEBUG

    deck.shuffle();
    // printf("Deck now has %d cards\n", (int)(deck.getDeck()->size()));

    Player player;
    player.giveCard(deck);
    player.giveCard(deck);

    printf("The game begins\n");

    while(!quitGame) {

        cin >> userLine;

        if(userLine == "quit" || userLine == "exit")
            quitGame = true;
        else if(userLine == "stand" || userLine == "s"){

            //todo
        }
        else if(userLine == "hit" || userLine == "h"){

            //todo
        }
        else if(userLine == "list" || userLine == "l"){

            player.printHand();
            // printf("Deck now has %d cards\n", (int)(deck.getDeck()->size()));
        }
        else if(userLine == "help"){
            printf("Your goal in this game is to get your points as close "
                "as possible to 21\n"
                "You can:\n'hit' to take another card\n"
                "'stand' to check the dealer\n"
                "'list' to check your hand\n"
                "'quit' or 'exit' to end the program and\n"
                "'help' to bring up this text again.\n");
        }
    }

    return 0;
}

/* one more thing , you should use assert() and static_assert() to enforce 
   class invariants and pre-conditions, and post-conditions*/