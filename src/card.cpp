#include "card.h"
#include <string>

Card::Card() {

}

Card::~Card() {

}

int Card::getValue() {

	return value;
}

std::string Card::getSuit() {

	switch(suit) {
		case 0:
			return "spades";

		case 1:
			return "hearts";

		case 2:
			return "diamonds";

		case 3:
			return "clubs";
	}
}