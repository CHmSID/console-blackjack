#include "player.hpp"
#include "dealer.hpp"
#include "deck.hpp"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::string;
using std::tolower;
using std::cin;
using std::srand;
using std::time;

void newGame(Deck& deck, Player& player, Dealer& dealer);
void printPlayerStatus(Player& player);
void toLowerCase(string& s);
void printHelp();

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
        toLowerCase(userLine);

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

                printf("Dealer beats you by %d points, you loose.\n",
                    dealer.getPoints() - player.getPoints());
                newGame(deck, player, dealer);
            }
            else if(dealer.getPoints() < player.getPoints()){

                printf("You beat the dealer by %d points, you win!\n",
                    player.getPoints() - dealer.getPoints());
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
            printPlayerStatus(player);

            if(player.getPoints() > 21){

                printf("You hit over 21 by %d points, you loose.\n",
                    player.getPoints() - 21);
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
            
            printHelp();
        }
    }

    return 0;
}

void newGame(Deck& deck, Player& player, Dealer& dealer){

    
    string choice = "";

    do{
        printf("Would you like to play?(Y/n)\n");
        cin >> choice;

        toLowerCase(choice);

        if(choice == "y"){

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
            printPlayerStatus(player);
        }
        else if(choice == "help"){

            printHelp();
        }
        else if(choice == "n"){

            exit(0);
        }
    }while(choice != "y" && choice != "n");
}

void printPlayerStatus(Player& player){

    printf("You have %d points, your cards are:\n", player.getPoints());
    player.printHand();
}

void toLowerCase(string& s){

    for(int i = 0; i < s.size(); i++){

        s[i] = tolower(s[i]);
    }
}

void printHelp(){

    printf("Your goal in this game is to get your points as close "
           "as possible to 21\n"
           "Cards 2-9 count as their face values,\n"
           "Jack, Queen and King count as 10 points and\n"
           "Aces count as either 1 or 11, whichever is more "
           "favourable in your situation.\n"
           "You can:\n'hit'('h') to take another card\n"
           "'stand'('s') to check the dealer\n"
           "'list'('l') to check your hand\n"
           "'quit' or 'exit' to end the program and\n"
           "'help' to bring up this text again\n");
}