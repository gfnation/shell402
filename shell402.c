#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define LARGE_COMM 7

char* getLine(FILE* stream);

void main(int argc, char** argv)
{
    int exit1 =0;
    //CHANGE AFTER TESTING; TOO LARGE
    char * buffer = malloc(sizeof(char) * 1000);
    if(argc > 2)
    {
        fprintf(stderr, "Wrong number of commands.\n");
        exit(1);
    }

    while(exit1 == 0)
    {
        if(argc==1)
        {
            printf("shell402>>");
            fgets(buffer, 100, stdin);
            executeLine(buffer);
       }
        else
        {
            FILE * tempfile;
            char * filename = malloc(sizeof(char) * strlen(argv[1]));
            strcpy(filename, argv[1]);
            if(tempfile = fopen(filename, "r") == NULL)
            {
                fprintf(stderr, "File could not be opened.\n");
                exit(1);
            }
            while(!feof(tempfile))
            {
                buffer = getLine(tempfile);
                executeLine(buffer);
            }
        }
    }
}

int executeLine(char * line)
{
    char * token;
    token = strtok(line, " ");
    if(token == NULL)
    {
        printf("SHITS BROKEN");
        exit(1);
    }
    if(strcmp(line, "quit") == 0)
    {
        return quit();
    }
    else if(strcmp(line, "wd") ==0)
    {
        wd();
        return 0;
    }
    else if(strcmp(line, "list") == 0)
    {
        execlp("list", NULL);
    }
}
