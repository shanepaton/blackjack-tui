#include <stdio.h>
#include <time.h>
#include "greetings.h"
#include "fileio.h"
#include "stats.h"
#include "cards.h"

void deal(int randNumber, Card cardToModify, int arrayOfCards[]) {
    static char *suits = "SDHC";
    static char faces[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};

    printf ("%c%c\n", faces[randNumber%13], suits[randNumber/13]);

    printf("%c\n", randNumber);

}


int main(){
    
    srand(time(NULL));
    //TODO: make default name "The Player"-

    char* name;
    int tokens = 1000;
    Card playerCards[5];

    char* tbMOne = readFile("names.txt", rand() % 100);
    Card tbmOneCards[5];

    char* tbMTwo = readFile("names.txt", rand() % 100);
    Card tbmTwoCards[5];

    char* tbMThree = readFile("names.txt", rand() % 100);
    Card tbmThreeCards[5];

    char* tbMFour = readFile("names.txt", rand() % 100);
    Card tbmFourCards[5];


    //Intro
    //FIXME: Handle blank name from config
    greet(readFile("config.txt", 1));
    
    printf("%s, %s, %s, and %s are sitting at the table.\n", strtok(tbMOne,"\n"), strtok(tbMTwo,"\n"), strtok(tbMThree,"\n"), strtok(tbMFour,"\n"));
    printf("The game starts.\n");
    printf("You and your tablemates are dealt two cards.\n");

    //Deal cards

    // No one could ever possibly have more than 5 cards but... 
    int cardsPulled[30];
    
    // 0 - 51
    deal(51, playerCards[0], cardsPulled);
    

    return 0;
}