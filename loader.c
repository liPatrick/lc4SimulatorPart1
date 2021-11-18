#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loader.h"

char* Open_File(char* fileName, size_t maxSize) {
    FILE* file = fopen(fileName, "r");
    char* data;
    size_t n = 0;
    int c;

    if (file == NULL) {
        printf ("Couldn't open file\n");
        return NULL; //could not open file
    }

    data = malloc(maxSize);

    while ((c = fgetc(file)) != EOF) {
        data[n] = (char) c;
        n++; 
    }

    data[n] = '\0';        

    fclose(file);

    return data;

}

void Close_File(char* filePointer) {
    free(filePointer);
}