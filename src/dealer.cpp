#include "dealer.hpp"
#include <stdio.h>
#include <vector>

void Dealer::revealCard()const{

    printf("Dealer reveals his card: %s of %s\n",
        playerHand.at(0).getVerboseValue(), //see player.hpp for both
        playerHand.at(0).getSuit());
}

void Dealer::fillHand(Deck& deck){

    while(getPoints() < 17){

        giveCard(deck);
    }
}