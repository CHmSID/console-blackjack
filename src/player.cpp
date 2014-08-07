#include "player.h"
#include <vector>
#include <stdio.h>

Player::Player() {

}

Player::~Player() {

}

void Player::giveCard() {

}

void Player::emptyHand() {

}

int Player::getPoints() {

	return 0;
}

void Player::printHand() {

	printf("You have %d points, your cards are:\n", getPoints());
	for(int i = 0; i < playerHand.size(); i++) {

		// printf("%d of %s", playerHand.at(i).)
	}
}