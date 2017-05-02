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
    char * pathname = malloc(sizeof(char) *1000);
    char mode;
    DIR * currDIR;
    struct dirent * dir_dirent;
    struct stat info;
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
                
                currDIR = opendir(pathname);
                while((dir_dirent = readdir(currDIR)) != NULL)
                {
                    char * filepath = malloc(sizeof(char)* strlen(dir_dirent->d_name) + (sizeof(char) * strlen(pathname) + 2);
                    strcat(filepath, pathname);
                    strcat(filepath,"/" );
                    strcat(filepath, dir_dirent->d_name);
                    if(stat(filepath, &info) == -1)
                    {
                        fprintf(stderr,"Couldn't get stat on file");
                        exit(1);
                    }
                    fprintf(stdout, "%s\t Size:%d\t Inode:%d\t Permissions:%d\n", dir_dirent->d_name, info.st_size,  info.st_ino, info.st_mode);
                }
            }
            else if(mode =='h')
            {
                //TODO: show hidden files in current path
                pathname = ".";
                currDIR = opendir(pathname);
                while((dir_dirent =readdir(currDIR))!=NULL)
                {
                    if(dir_dirent->d_name[0] == '.')
                    {
                        fprintf(stdout, "%s\n", dir_dirent->d_name);
                    }
                }
            }
            else
            {
                //TODO: print all non-hidden files in specified filename
                strcpy(pathname, argv[1]);
                currDIR = opendir(pathname);
                while((dir_dirent = readdir(currDIR))!=NULL){
                    if(dir_dirent->d_name[0] != '.')
                    {
                       fprintf(stdout, "%s\n", dir_dirent->d_name); 
                    }
                }
            }
        }
        else if(argc == 3)
        {
            mode = argv[1][1];
            if(mode == 'i')
            {
                //TODO: show information at specified pathname
                strcpy(pathname, argv[2]);
                if(stat(pathname, &info) == -1)
                {
                    fprintf(stderr,"Couldn't get stat on file");
                    exit(1);
                }
                currDIR = opendir(pathname);
            }
            else if(mode == 'h')
            {
                //TODO: show hidden files in specified path
                strcpy(pathname, argv[2]);
                currDIR = opendir(pathname);
                while((dir_dirent =readdir(currDIR))!=NULL)
                {
                    if(dir_dirent->d_name[0] == '.')
                    {
                        fprintf(stdout, "%s\n", dir_dirent->d_name);
                    }
                }
            }
            else
            {
                //Shouldn't come here. Chose a wrong mode
                fprintf(stderr, "The list mode must be <-i> or <-h>");
                exit(1);
            }
        }
        else
        {
            //only one option with 1 argc. Print non-hidden files in current directory
            pathname=".";
            currDIR = opendir(pathname);
            while((dir_dirent = readdir(currDIR))!=NULL)
            {
                    if(dir_dirent->d_name[0] != '.')
                    {
                       fprintf(stdout, "%s\n", dir_dirent->d_name); 
                    }
                }
        }
    }
    else
    {
        fprintf(stderr, "The wrong number of arguments are inc");
    }
}