#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	printf("PID= %d, PPID= %d\n", getpid(), getppid());
	if((execl("/bin/ls","ls","-l", NULL))==-1)
        {
                perror("execlp");
                exit(1);
        }
        printf("Exiting from the process\n");
}
