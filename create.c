#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char ** argv)
{
    if(argc == 3 || argc == 4)
    {
        if(argc == 3)
        {
            if(argv[1][1] == 'f')
            {
                char * filepath = malloc(sizeof(char) * strlen(argv[2]));
                strcpy(filepath, argv[2]);
                int newFile;
                if(newFile = open(filepath, O_RDWR | O_CREAT, 0644) == -1)
                {
                    fprintf(stderr, "Open failed.\n");
                    exit(1);
                }
            }
            else if(argv[1][1] == 'd')
            {
                char * dirpath = malloc(sizeof(char) * strlen(argv[2]));
                strcpy(dirpath, argv[2]);
                int newDir;
                if((newDir = mkdir(dirpath, 0750)) == -1)
                {
                    fprintf(stderr, "Directory open fail");
                    exit(1);
                }
            }
            else
            {
                fprintf(stderr, "Incorrect option selected");
                exit(1);
            }
        }
        else
        {
            char * oldname = malloc(sizeof(char) * strlen(argv[2]));
            char * newname = malloc(sizeof(char) * strlen(argv[3]));
            strcpy(oldname, argv[2]);
            strcpy(newname, argv[3]);
            int linky;
            if(argv[1][1] == 'h')
            {
                if((linky = link(oldname, newname)) == -1)
                {
                    fprintf(stderr, "The paths couldn't be linked.\n");
                    exit(1);
                }
            }
            else if(argv[1][1] == 's')
            {
                if((linky = symlink(oldname, newname))== -1)
                {
                    fprintf(stderr, "Couldn't make the symbolic link\n");
                    exit(1);
                }
            }
            else
            {
                fprintf(stderr, "option is incorrect.");
                exit(1);
            }
        }    
    }
    else
    {
        fprintf(stderr, "The number of args is incorrect.\n");
        exit(1);
    }
}