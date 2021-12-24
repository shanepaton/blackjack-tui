#include <stdio.h>
#include <time.h>

#include "greetings.h"
#include "fileio.h"
#include "cards.h"
#include "player.h"

void deal(int randNumber, Card cardToModify[], int pulledCards[], int pulledCardsIndex) {
    static char *suits = "SDHC";
    static char faces[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};

    // int initialSuit = faces[randNumber%13];
    // int initialValue = suits[randNumber/13];

    // printf("%d\n", initialValue);
    // printf("%d\n", initialSuit);

    // if(arrayOfCards[arrayOfCardsIndex] == 0) {
    //     cardToModify.suit = suits[randNumber/13];
    //     cardToModify.value = faces[randNumber%13];
    //     arrayOfCards[arrayOfCardsIndex] = randNumber;
    // }
    
    // else {
    //     printf("Card already dealt.\n");
    // }


    // //cardToModify.suit = suits + randNumber % 4;
    // printf ("%c%c\n", faces[randNumber%13], suits[randNumber/13]);

    // printf("%c\n", randNumber);

}


int main(){
    srand(time(NULL));
    
    Player player = {readFile("config.txt", 1), 1000 };

    Player tbmOne = {readFile("names.txt", rand() % 100), 1000 };
    Player tbmTwo = {readFile("names.txt", rand() % 100), 1000 };
    Player tbmThree = {readFile("names.txt", rand() % 100), 1000 };
    Player tbmFour = {readFile("names.txt", rand() % 100), 1000 };

    greet(player.name, tbmOne.name, tbmTwo.name, tbmThree.name, tbmFour.name);

    int cardsPulled[30];
    int cardsPulledIndex = 0;


    // 0 - 51
    deal(51, player.hand[0], cardsPulled, cardsPulledIndex);
    return 0;
}