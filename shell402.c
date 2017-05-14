#include "libraries.h"
#include "shellFunctions.h"
#include "token.h"
#include "input.h"
#define LARGE_COMM 7


void executeLine(char * line);

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
            buffer[strlen(buffer)] = '\0';
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

void executeLine(char * line)
{
    char * token;
    token = strtok(line, " ");
    if(token == NULL)
    {
        printf("SHITS BROKEN");
        exit(1);
    }
    printf("%s %d", token,strcmp(token, "quit\n") );
    if(strcmp(token, "quit") == 0)
    {
        quit();
    }
    else if(strcmp(token, "wd") ==0)
    {
        wd();
    }
    else if(strcmp(line, "list") == 0)
    {
        execlp("list", NULL);
    }
    else
    {
        fprintf(stderr, "%s", "Command incorrect");
        exit(1);
    }
}
