#include "greetings.h"

void greet(char* name, char* tbOneName, char* tbTwoName, char* tbThreeName, char* tbFourName){
    //ASCII art
    printf(" ________  ___       ________  ________  ___  __          ___  ________  ________  ___  __       \n|\\   __  \\|\\  \\     |\\   __  \\|\\   ____\\|\\  \\|\\  \\       |\\  \\|\\   __  \\|\\   ____\\|\\  \\|\\  \\     \n\\ \\  \\|\\ /\\ \\  \\    \\ \\  \\|\\  \\ \\  \\___|\\ \\  \\/  /|_     \\ \\  \\ \\  \\|\\  \\ \\ \\___|\\ \\  \\/  /|_\n \\ \\   __  \\ \\  \\    \\ \\   __  \\ \\  \\    \\ \\   ___  \\  __ \\ \\  \\ \\   __  \\ \\  \\    \\ \\   ___  \\  \n  \\ \\  \\|\\  \\ \\  \\____\\ \\  \\ \\  \\ \\  \\____\\ \\  \\\\ \\  \\|\\  \\\\_\\  \\ \\  \\ \\  \\ \\  \\____\\ \\  \\\\ \\  \\ \n   \\ \\_______\\ \\_______\\ \\__\\ \\__\\ \\_______\\ \\__\\\\ \\__\\ \\________\\ \\__\\ \\__\\ \\_______\\ \\__\\\\ \\__\\\n    \\|_______|\\|_______|\\|__|\\|__|\\|_______|\\|__| \\|__|\\|________|\\|__|\\|__|\\|_______|\\|__| \\|__|\n\n");
    
    
    printf("Hello %s%s", strtok(name,"\n"), ", welcome to Blackjack!\n");

    printf("Would you like to join a table? (y/n) > ");

    char response[256];
    scanf("%s", response);
    if(strcmp(response, "y") == 0) {
        printf("You joined table %d.\n", rand() % 10);
    
        printf("%s, %s, %s, and %s are sitting at the table.\n", strtok(tbOneName,"\n"), strtok(tbTwoName,"\n"), strtok(tbThreeName,"\n"), strtok(tbFourName,"\n"));
        printf("The game starts.\n");
        printf("You and your tablemates are dealt two cards.\n");
    }
    else{
        printf("Goodbye!\n");
        exit(0);
    }
    
    
}