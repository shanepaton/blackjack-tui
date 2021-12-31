#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "player.h"

void turn(Player* p) {
	printf("It's Your turn.\n");
	printf("Stats:\n");
	printf("------------------YOUR STATS---------------------\n");
	printf("Tokens: %d\n", p->tokens);
	printf("Sum: %d\n", p->hand[0].value + p->hand[1].value + p->hand[2].value + p->hand[3].value + p->hand[4].value);
	//print out and ascii art of the hand
	for (int i = 0; i < p->hand_size; i++) {
		printf("┌────────┐");
	}
	printf("\n");
	for (int i = 0; i < p->hand_size; i++) {
		char* suit = p->hand[i].suit;
		// if (p->hand[i].suit == 'S') {
		// 	suit = 	"♠";
		// }
		// else if (p->hand[i].suit == 'D') {
		// 	suit = "♦";
		// }
		// else if (p->hand[i].suit == 'H') {
		// 	suit = 	"♥";
		// }
		// else if (p->hand[i].suit == 'C') {
		// 	suit = 	"♣";
		// }
		if(p->hand[i].value >= 10) {
			printf("│%d     %c│", p->hand[i].value, suit);
		} else{
			printf("│%d      %c│", p->hand[i].value, suit);
		}
	}
	char response[256];
	scanf("%s", response);
	if(strcmp(response, "b") == 0) {
		
	}
	else{
		printf("Goodbye!\n");
		exit(0);
	}
}