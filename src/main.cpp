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
void printPlayerStatus(Player& player);

int main() {

    srand(time(0));

    bool quitGame = false;
    string userLine;

    printf("Welcome to Blackjack!\n");
    printf("Type 'help' for instructions\n");

    Deck deck;

    Player player;
    Dealer dealer;

    newGame(deck, player, dealer);

    while(!quitGame) {

        cin >> userLine;

        if(userLine == "quit" || userLine == "exit")
            quitGame = true;
        else if(userLine == "stand" || userLine == "s"){

            printf("You stand\n");
            printf("Dealer takes cards\n");
            dealer.fillHand(deck);

            if(dealer.getPoints() > 21){

                printf("Dealer hits over 21 points, you win!\n");
                newGame(deck, player, dealer);
            }
            else if(dealer.getPoints() > player.getPoints()){

                printf("Dealer has more points than you, you loose.\n");
                newGame(deck, player, dealer);
            }
            else if(dealer.getPoints() < player.getPoints()){

                printf("You have more points than the dealer, you win!\n");
                newGame(deck, player, dealer);
            }
            else if(dealer.getPoints() == player.getPoints()){

                printf("It's a tie.\n");
                newGame(deck, player, dealer);
            }
        }
        else if(userLine == "hit" || userLine == "h"){

            printf("You hit\n");
            printf("Dealer gives you a card\n");
            player.giveCard(deck);

            if(player.getPoints() > 21){

                printf("You hit over 21 points, you loose.\n");
                newGame(deck, player, dealer);
            }
            else if(player.getPoints() == 21){

                printf("You got 21 points, you win!\n");
                newGame(deck, player, dealer);
            }
        }
        else if(userLine == "list" || userLine == "l"){

            printPlayerStatus(player);
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

    printf("Would you like to play?(Y/n)\n");

    string choice;
    cin >> choice;

    if(choice == "y" || choice == "Y"){

        deck.setNewDeck();
        printf("Dealer shuffles the deck...\n");
        deck.shuffle();

        player.emptyHand();
        dealer.emptyHand();

        printf("\nThe game now begins!\n");

        printf("Dealer gives you two cards\n");
        player.giveCard(deck);
        player.giveCard(deck);

        printf("Dealer takes one card\n");
        dealer.giveCard(deck);
        dealer.revealCard();
    }
    else{

        exit(0);
    }
}

void printPlayerStatus(Player& player){

    printf("You have %d points, your cards are:\n", player.getPoints());
    player.printHand();
}