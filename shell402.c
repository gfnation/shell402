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
            }
        }
    }
}

void executeLine(char * line)
{
    char * command = malloc(sizeof(char) * LARGE_COMM);
    command = getTokened(line, ' ');
    if((strcmp(command, "wd"))== 0)
    {
        wd();
    }
    else if(strcmp(command, "chwd") == 0)
    {
        char * pathname = malloc(sizeof(char) * 1000);
        pathname = getTokened(getRemaining(line, command), ' ');
        chwd(pathname);
    }
    else if(strcmp(command, "quit") ==0)
    {
        quit();
    }
    else if(strcmp(command, "create") == 0)
    {
        
    }
    else if(strcmp(command, "list") ==0)
    {

    }
    else
    {
        fprintf(stderr, "The command entered is not a valid option.\n");
        exit(1);
    }
}
