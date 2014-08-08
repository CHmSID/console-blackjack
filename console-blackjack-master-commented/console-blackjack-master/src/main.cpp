#include <stdio.h>
#include <iostream>
#include <string>
#include "player.h" // this should be at the top , as explained in player.h

using std::string;
using std::cin;

int main() {
	bool quitGame = false;
	/*std::*/string userLine;

	printf("Welcome to Blackjack!\n\n");
	printf("The game begins\n");

	Player player;
	player.giveCard();

	while(!quitGame) {

		/*std::*/cin >> userLine;

		if(userLine=="quit" || userLine=="exit")
			quitGame = true;
	}

	return 0;
}

/* one more thing , you should use assert() and static_assert() to enforce 
   class invariants and pre-conditions, and post-conditions*/