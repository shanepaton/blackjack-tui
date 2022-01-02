#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "cards.h"

typedef struct Player
{
    char* name;
    int tokens;
    int hand_size;
    Card hand[16];
}Player;

void turn(Player* p, bool stillPlaying);


#endif