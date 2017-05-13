#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>

void wd()
{
    char * buff = malloc(sizeof(char) * (PATH_MAX +1));

    fprintf(stdout, "%s", getcwd(NULL, PATH_MAX +1));
}

void chwd(char* path)
{
    int success =0;
    if((success = chdir(path)) == -1)
    {
        fprintf(stderr, "The directory couldn't be opened");
        exit(1);
    }
}

int quit()
{
   fprintf(stdout, "Goodbye\n");
   return 1; 
}