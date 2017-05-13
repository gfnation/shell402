#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

char* getLine(FILE* stream)
{
    
    char * buffer = malloc(sizeof(char) * 256);

    int count =0;
    while(; buffer[count] != '\n'; count ++)
    {
        buffer[count] = stream[count];
    }
    buffer[count] = '\0';

    return buffer;
}