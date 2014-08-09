#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"
#include <stdio.h>

Player::Player() {

}

Player::~Player() {

}

void Player::giveCard(Deck& deck) {

    if(deck.getDeck()->size() < 0){
        printf("ERROR: no cards in deck");
        return;
    }

    Card card = deck.getDeck()->at(deck.getDeck()->size() - 1);
    deck.getDeck()->pop_back();
    playerHand.push_back(card);
}

void Player::emptyHand() {

    playerHand.erase(playerHand.begin(), playerHand.begin() + playerHand.size());
}

int Player::getPoints() {

    int points = 0; //initialise to 0, otherwise it creates undefined behaviour

	//since aces have a special meaning to points, move them to the end of the
    //hand and deal with them last
    for(int i = 0; i < (int)(playerHand.size() / 2); i++){

        if(playerHand.at(i).getCardId() == 0){ //ace

            for(int k = playerHand.size(); i > (int)(playerHand.size() / 2); i--){

                if(playerHand.at(k).getCardId() != 0){

                    //swap
                    Card temp = playerHand.at(i);
                    playerHand.at(i) = playerHand.at(k);
                    playerHand.at(k) = temp;

                    //look for the next ace
                    break;
                }
            }
        }
    }

    //iterate through all cards in hand and add the points
    //ace counts as eleven unless it goes over 21, then it counts as one
    //2-9 count as their face values
    //10, jack, queen and king count as 10

    for(int i = 0; i < playerHand.size(); i++) {

        //2-9
        if(playerHand.at(i).getCardId() > 0 && playerHand.at(i).getCardId() < 9){

            points += (playerHand.at(i).getCardId() + 1);
        }
        //10, jack, queen, king
        else if(playerHand.at(i).getCardId() > 8 &&
                playerHand.at(i).getCardId() < 13){

            points += 10;
        }
        //ace
        else if(playerHand.at(i).getCardId() == 0){

            if(points + 11 <= 21)
                points += 11;
            else
                points++;
        }
    }

    return points;
}

void Player::printHand() {

	printf("You have %d points, your cards are:\n", getPoints());
	for(int i = 0; i < playerHand.size(); i++) {

        printf("%s of %s\n",
            playerHand.at(i).getVerboseValue(),
            playerHand.at(i).getSuit());
    }
}