#ifndef FILEIO_H
#define FILEIO_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void writeFile(char* file, char* data);
char* readFile(char* path, int line_no );

#endif