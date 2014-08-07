#include <stdio.h>
#include <iostream>
#include <string>
#include "player.h"

int main() {
	bool quitGame = false;
	std::string userLine;

	printf("Welcome to Blackjack!\n\n");
	printf("The game begins\n");

	Player player;
	player.giveCard();

	while(!quitGame) {

		std::cin >> userLine;

		if(userLine=="quit" || userLine=="exit")
			quitGame = true;
	}

	return 0;
}