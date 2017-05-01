#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char** argv)
{
    char * pathname;
    char mode;
    //make sure correct number of command line arguments
    if(argc >0 && argc <=3)
    {
        if(argc == 2)
        {
            mode = argv[1][1];
            if(mode == 'i')
            {
                //TODO: information of current path
                pathname = ".";
            }
            else if(mode =='h')
            {
                //TODO: show hidden files in current path
                pathname = ".";
            }
            else
            {
                //TODO: print all non-hidden files in specified filename
                strcpy(pathname, argv[1]);
            }
        }
        else if(argc == 3)
        {
            mode = argv[1][1];
            if(mode == 'i')
            {
                //TODO: show information at specified pathname
                strcpy(pathname, arg[2]);
            }
            else if(mode == 'h')
            {
                //TODO: show hidden files in specified path
                strcpy(pathname, arg[2]);
            }
            else
            {
                //Shouldn't come here. Chose a worng mode
                fprintf(stderr, "The list mode must be <-i> or <-h>");
                exit(1);
            }
        }
        else
        {
            //only one option with 1 argc. Print non-hidden files in current directory
            pathname=".";
        }
    }
}