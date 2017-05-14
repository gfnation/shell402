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
    char * line = getcwd(buff, PATH_MAX+1);
    fprintf(stdout, "%s", line);
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

void quit()
{
   fprintf(stdout, "Goodbye\n");
   exit(0);
}