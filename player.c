#include "player.h"

typedef struct Player
{
    char* name;
    int tokens;
    Card* hand[5];
}Player;
