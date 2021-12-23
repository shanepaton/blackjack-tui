#include "fio.h"

void writeFile(char* file, char* data){
    FILE* fp = fopen(file, "r+");
    fprintf(fp, "%s", data);
    fclose(fp);
}

int readFile(char* file, int ln, char* data){
    FILE* fp = fopen(file, "r+");

    char line[4096];
    int i = 0;
    while(fgets(line, sizeof(line), fp) != NULL){
        if(i == ln){
            memcpy(data, line, sizeof(line));
            return 1;
        }
        i++;
    }
    
    // close the file
    fclose(fp);
}