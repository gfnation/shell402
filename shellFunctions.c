#include <limits.h>
void wd()
{
    fprintf(stdout, "%s", getcwd(NULL, PATH_MAX +1));
}

void chwd(char* path)
{
    int success =0;
    if(success = chdir(path) == 0)
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