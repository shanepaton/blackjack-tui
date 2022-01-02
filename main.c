#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "greet.h"
#include "fileio.h"
#include "cards.h"
#include "player.h"
#include "erand.h"

void deal(int randNumber, Player* p,int cardIndex) {
    static char *suits = "SDHC";
    static char faces[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};

    int randomChosenNumber = randNumber%13;
    int numberValue;

    if(randomChosenNumber >0 && randomChosenNumber <8) {
        numberValue = randomChosenNumber;
    }
    else if(randomChosenNumber == 10) {
        numberValue = 10;
    }
    else if(randomChosenNumber == 11) {
        numberValue = 10;
    }
    else if(randomChosenNumber == 12) {
        numberValue = 10;
    }
    else if(randomChosenNumber == 0) {
        numberValue = 1;
    }

    int initialSuit = suits[randNumber/13];
    int initialValue = faces[randNumber%13];


    p->hand[cardIndex].suit =  initialSuit;
    p->hand[cardIndex].value = numberValue;
    p->hand_size++;

}


int main(){
    srand(time(NULL));

    Player player = {readFile("config.txt", 1), 1000 };

    Player tbmOne = {readFile("names.txt", rand() % 100), 1000 };
    Player tbmTwo = {readFile("names.txt", rand() % 100), 1000 };
    Player tbmThree = {readFile("names.txt", rand() % 100), 1000 };
    Player tbmFour = {readFile("names.txt", rand() % 100), 1000 };

    greet(player.name, tbmOne.name, tbmTwo.name, tbmThree.name, tbmFour.name);
    
    // --- TURN LOGIC ---
    
    bool stillPlaying = true;
        
    int cardsPulled[30];
    int cardsPulledIndex = 0;
    int round = 0;

    // First turn deal two cards to each player
    for(int i = 0; i < 2; i++) {
        deal(erand(0, 51, cardsPulled, cardsPulledIndex), &player, player.hand_size);
        deal(erand(0, 51, cardsPulled, cardsPulledIndex), &tbmOne, tbmOne.hand_size);
        deal(erand(0, 51, cardsPulled, cardsPulledIndex), &tbmTwo, tbmTwo.hand_size);
        deal(erand(0, 51, cardsPulled, cardsPulledIndex), &tbmThree, tbmThree.hand_size);
        deal(erand(0, 51, cardsPulled, cardsPulledIndex), &tbmFour, tbmFour.hand_size);
    }
    while(stillPlaying) {
        // Player's turn
        turn(&player, stillPlaying);
        // TBM's turn
        if(tbmOne.hand_size < 16) {
            deal(erand(0, 51, cardsPulled, cardsPulledIndex), &tbmOne, tbmOne.hand_size);
            printf("%s hits.\n", tbmOne.name);
        }
        else {
            printf("%s stays.\n", tbmOne.name);
        }

        if(tbmTwo.hand_size < 16) {
            deal(erand(0, 51, cardsPulled, cardsPulledIndex), &tbmTwo, tbmTwo.hand_size);
            printf("%s hits.\n", tbmTwo.name);
        }
        else {
            printf("%s stays.\n", tbmTwo.name);
        }

        if(tbmThree.hand_size < 16) {
            deal(erand(0, 51, cardsPulled, cardsPulledIndex), &tbmThree, tbmThree.hand_size);
            printf("%s hits.\n", tbmThree.name);
        }
        else {
            printf("%s stays.\n", tbmThree.name);
        }

        if(tbmFour.hand_size < 16) {
            deal(erand(0, 51, cardsPulled, cardsPulledIndex), &tbmFour, tbmFour.hand_size);
            printf("%s hits.\n", tbmFour.name);
        }
        else {
            printf("%s stays.\n", tbmFour.name);
        }

        round++;
    }

    return 0;
}