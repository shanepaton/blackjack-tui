#include <stdio.h>
#include <stdlib.h>

#include "erand.h"

int erand(int min, int max, int excusion[], int excusionIndex) {
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
            //printf("%d\n", randNum);
            excusion[excusionIndex] = randNum;

            //printf("%d, ", excusion[excusionIndex]);
            return randNum;

        }
    }   
}