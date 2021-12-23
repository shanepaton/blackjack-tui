#ifndef FIO_H
#define FIO_H
#include <stdio.h>
#include <string.h>


void writeFile(char* file, char* data);
int readFile(char* file, int ln, char* out);

#endif