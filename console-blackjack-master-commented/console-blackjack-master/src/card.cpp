#include "card.h"
//#include <string> // no need to include this again , already included from card.h

using std::string; // you can use the "using" keyword with freedom in cpp files

//Card::Card()/*this space*/{ // i don't like leaving a space between parenthesis and curly brackets

//}

//Card::~Card(){

//}

int Card::getValue()const{ // should be const , since it will not modify any of the member variables

	return value;
}

// no need for full qualified names in cpp files (only in very rare occasions)
/*std::*/string Card::getSuit()const{
	
	// get in the habbit of writing break after every case in a switch
	// even if it won't be executed , just so you don't get bitten when you least expect it
	// in a different code 
	// also default cases are good , they can be used to indicate errors
	switch(suit) {
		case 0:
			return "spades";
			break;
		case 1:
			return "hearts";
			break;
		case 2:
			return "diamonds";
			break;
		case 3:
			return "clubs";
			break;
		default:
			return "WHAT?!"; // so if you are debugging and see "WHAT?!" as a value of anything
							 // you know where it came from
			break; // just for consistency
	}
}