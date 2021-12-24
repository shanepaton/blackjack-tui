#include <stdio.h>
#include <time.h>

#include "greetings.h"
#include "fileio.h"
#include "cards.h"
#include "player.h"

int excusionRand(int min, int max, int excusion[], int excusionIndex) {
    while (1) {
        int randNum = rand() % (max - min + 1) + min;
        int i;
        for (i = 0; i < sizeof(excusion); i++) {
            if (randNum == excusion[i]) {
                break;
            }
        }
        if (i == sizeof(excusion)) {
            // set the excusion array to the new number
            printf("%d\n", randNum);
            excusion[excusionIndex] = randNum;

            printf("%d, ", excusion[excusionIndex]);
            return randNum;

        }
    }   
}

void deal(int randNumber, Card cardToModify[],int cardIndex) {
    static char *suits = "SDHC";
    static char faces[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};

   

    int initialSuit = faces[randNumber%13];
    int initialValue = suits[randNumber/13];
    
    printf("%c%c\n", initialSuit, initialValue);

    cardToModify[cardIndex].suit = initialSuit;
    cardToModify[cardIndex].value = initialValue;

    // if(pulledCards[arrayOfCardsIndex] == 0) {
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
    //bool stillPlaying = true;

    int cardsPulled[30];
    int cardsPulledIndex = 0;

    // 0 - 51
    deal(excusionRand(0, 51, cardsPulled, cardsPulledIndex), player.hand[0], player.hand_size);
    printf("asd");
    //printf("%d\n", player.hand[0]->value);
    return 0;
}