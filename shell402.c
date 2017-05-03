#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

void main(int argc, char** argv)
{
    int exit =0;
    char buffer[256];
    if(argc > 2)
    {
        fprintf(stderr, "Wrong number of commands.\n");
        exit(1);
    }

    while(exit == 0)
    {
        if(argc=1)
        {
            scanf("%s", buffer);
            char * command = malloc(sizeof(char) * 8);
            

        }
        else
        {
            FILE * tempfile;
            char filename[];
            strcpy(filename, argv[1]);
            if(tempfile = fopen(filename, "r") == NULL)
            {
                fprintf(stderr, "File could not be opened.\n");
                exit(1);
            }


        }

    }

}