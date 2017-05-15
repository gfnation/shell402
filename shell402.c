#include "libraries.h"
#include "shellFunctions.h"
#include "token.h"
#include "input.h"
#define LARGE_COMM 7


void executeLine(char * line, char * listPath, char * createPath);

void main(int argc, char** argv)
{
    char * listPath = malloc(sizeof(char) * (PATH_MAX + 6));
    char * createPath = malloc(sizeof(char) * (PATH_MAX + 8));

    if((getcwd(listPath, PATH_MAX) == NULL) && (getcwd(createPath, PATH_MAX) == NULL))
    {
        fprintf("%s", "Cannot get current working directory\n");
        exit(1);
    } 
    strcat(listPath, "/list");
    strcat(listPath, "/create");

    int exit1 =0;
    //CHANGE AFTER TESTING; TOO LARGE
    char * buffer = malloc(sizeof(char) * (PATH_MAX + 1));
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
            buffer[strlen(buffer) -1] = '\0';
            executeLine(buffer, listPath, createPath);
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
                executeLine(buffer, listPath, createPath);
            }
        }
    }
}

void executeLine(char * line, char * listPath, char * createPath)
{
    char * token;
    token = strtok(line, " ");
    if(token == NULL)
    {
        printf("SHITS BROKEN");
        exit(1);
    }
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
        pid_t child;
        if((child = fork() == 0))
        {
        execlp(listPath, "list", NULL);
        }
        else
        {
            wait(0);
            if(child == (pid_t)(-1))
            {
                fprintf(stderr, "The fork failed");
                exit(1);
            }
        }
    }
    else
    {
        fprintf(stderr, "%s\n", "Command incorrect");
        exit(1);
    }
}
