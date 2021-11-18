
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "loader.h"

#define MAX_OBJECT_SIZE 10000

typedef struct section_st {
  char* headerName; 
  char* address; 
  int n; 
  int charSize; //1 byte for xC3B7, and xF17E, 2 bytes otherwise
  char* line; //for x715E
  char* fileIndex; //for x715E
  
  int currNCount; //used for processing section data

} Section; 


int main (int argc, char**argv) {
    char* objectContent; 
    Section currSegmentHeader; 
    int i; 

    objectContent = Open_File("divide.obj", MAX_OBJECT_SIZE); 
    if (objectContent == NULL) {
        return 1;
    }

    while (objectContent[i] != '\0') {       /* Stop looping when we reach the null-character. */
        printf("%c", objectContent[i]);    /* Print each character of the string. */
        i++;
    }

    free(objectContent); 

    return 1; 

}