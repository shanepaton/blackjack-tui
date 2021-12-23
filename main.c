#include <stdio.h>
#include <time.h>
#include "greetings.h"
#include "fio.h"

char** tableMates;

void tablemateGeneratorVfour(char** cpp){
    char* t1;
    char* t2;
    char* t3;
    char* t4;
    readFile("tablemates.txt", rand() % 13, t1);
    readFile("tablemates.txt", rand() % 13, t2);
    readFile("tablemates.txt", rand() % 13, t3);
    readFile("tablemates.txt", rand() % 13, t4);
    memcpy(tableMates[0], t1, sizeof(t1));
    memcpy(tableMates[1], t2, sizeof(t2));
    memcpy(tableMates[2], t3, sizeof(t3));
    memcpy(tableMates[3], t4, sizeof(t4));
    
}

int main(){
    *(int*)0 = 0;
    srand(time(NULL));
    char* name;
    readFile("config.txt", 0, name);
    greet(name);
    tablemateGeneratorVfour(tableMates);
    printf("piss");
    return 0;
}