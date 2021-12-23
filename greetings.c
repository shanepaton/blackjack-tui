#include "greetings.h"

void greet(char* user){
    //ASCII art
    printf(" ________  ___       ________  ________  ___  __          ___  ________  ________  ___  __       \n|\\   __  \\|\\  \\     |\\   __  \\|\\   ____\\|\\  \\|\\  \\       |\\  \\|\\   __  \\|\\   ____\\|\\  \\|\\  \\     \n\\ \\  \\|\\ /\\ \\  \\    \\ \\  \\|\\  \\ \\  \\___|\\ \\  \\/  /|_     \\ \\  \\ \\  \\|\\  \\ \\ \\___|\\ \\  \\/  /|_\n \\ \\   __  \\ \\  \\    \\ \\   __  \\ \\  \\    \\ \\   ___  \\  __ \\ \\  \\ \\   __  \\ \\  \\    \\ \\   ___  \\  \n  \\ \\  \\|\\  \\ \\  \\____\\ \\  \\ \\  \\ \\  \\____\\ \\  \\\\ \\  \\|\\  \\\\_\\  \\ \\  \\ \\  \\ \\  \\____\\ \\  \\\\ \\  \\ \n   \\ \\_______\\ \\_______\\ \\__\\ \\__\\ \\_______\\ \\__\\\\ \\__\\ \\________\\ \\__\\ \\__\\ \\_______\\ \\__\\\\ \\__\\\n    \\|_______|\\|_______|\\|__|\\|__|\\|_______|\\|__| \\|__|\\|________|\\|__|\\|__|\\|_______|\\|__| \\|__|\n\n");
    printf("Hello %s%s", user, ", welcome to Blackjack!\n");
    // ask the user "Join a table" and if they say yes then ask them to enter a table number
    printf("Would you like to join a table? (y/n) > ");
    // scanf for the user's response and error check
    char response[256];
    scanf("%s", response);
    if(strcmp(response, "y") == 0) {
        printf("You joined table %d.\n", rand() % 10);
    }
    else if(strcmp(response, "n") == 0){
        printf("Goodbye!\n");
        //exit(0);
    }
    else{
        printf("Wow, you're so dumb! How do you even mess this up?!\n");
        //exit(1);
    }
    
    
}