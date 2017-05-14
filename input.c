#include "libraries.h"

char* getLine(FILE* stream)
{
    
    char * buffer = malloc(sizeof(char) * 256);
    char curr;

    int loopy =0;
    fscanf(stream, "%c", &curr);
    while(curr = '\n')
    {
        buffer[loopy++] = curr;
        fscanf(stream, "%c", &curr);
    }
    buffer[loopy] = curr;
    return buffer;
}