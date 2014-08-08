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

	return 0;
}

void Player::printHand() {

	printf("You have %d points, your cards are:\n", getPoints());
	for(int i = 0; i < playerHand.size(); i++) {

        printf("%s of %s\n",
            playerHand.at(i).getVerboseValue(), playerHand.at(i).getSuit());
    }
}