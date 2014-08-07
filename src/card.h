#ifndef CARD_H
#define CARD_H
#include <string>

class Card {

public:
	Card();
	~Card();

	int getValue();
	std::string getSuit();

private:
	int suit;
	int value;
};

#endif