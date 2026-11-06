#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc,char *argv[])
{
        DIR *ptr;
        if(argc == 1)
        {
                ptr = opendir("./");
        }
        else
        {
                if(strchr(argv[argc-1], '/'))
                        ptr = opendir(argv[argc-1]);
                else
                        ptr = opendir("./");
        }

        if(ptr == NULL)
        {
                perror("OpenDIR");
                return 1;
        }

        struct dirent *p;
        while((p = readdir(ptr)) != NULL)
        {
		  if(p->d_name[0] != '.')
                        printf("%s ", p->d_name);
        }
        printf("\n");
        closedir(ptr);
}

