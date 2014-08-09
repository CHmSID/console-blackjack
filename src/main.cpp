#include "player.hpp"
#include "dealer.hpp"
#include "deck.hpp"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::string;
using std::cin;
using std::srand;
using std::time;

void newGame(Deck& deck, Player& player, Dealer& dealer);

int main() {

    srand(time(0));

    bool quitGame = false;
    string userLine;

    printf("Welcome to Blackjack!\n");
    printf("Type 'help' for instructions\n\n");

    Deck deck;

    Player player;
    Dealer dealer;

    newGame(deck, player, dealer);

    while(!quitGame) {

        cin >> userLine;

        if(userLine == "quit" || userLine == "exit")
            quitGame = true;
        else if(userLine == "stand" || userLine == "s"){

            //todo
        }
        else if(userLine == "hit" || userLine == "h"){

            //stodo
        }
        else if(userLine == "list" || userLine == "l"){

            printf("You have %d points, your cards are:\n", player.getPoints());
            player.printHand();
        }
        else if(userLine == "help"){
            printf("Your goal in this game is to get your points as close "
                "as possible to 21\n"
                "You can:\n'hit' to take another card\n"
                "'stand' to check the dealer\n"
                "'list' to check your hand\n"
                "'quit' or 'exit' to end the program and\n"
                "'help' to bring up this text again\n");
        }
    }

    return 0;
}

/* one more thing , you should use assert() and static_assert() to enforce 
   class invariants and pre-conditions, and post-conditions*/

void newGame(Deck& deck, Player& player, Dealer& dealer){

    deck.setNewDeck();
    deck.shuffle();

    player.emptyHand();
    dealer.emptyHand();

    printf("The game now begins!\n");

    player.giveCard(deck);
    player.giveCard(deck);

    dealer.giveCard(deck);
    dealer.revealCard();
}