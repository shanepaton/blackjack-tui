#ifndef PLAYER_H
#define PLAYER_H
#include "cards.h"

typedef struct Player
{
    char* name;
    int tokens;
    Card* hand[5];
}Player;


#endif