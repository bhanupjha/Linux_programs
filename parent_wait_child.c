// Program for Creating a multiple children processes and make the parent wait for the children to terminate.

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int n, ret, status, retval;
	if(argc != 2)
	{
		printf("Argument doesn't provide properly\n");
		return 1;
	}
	n = atoi(argv[1]); 
	srand(getpid());
	for(int i=0; i<n; i++)
	{
		ret=fork();
		if(ret==0)
		{
			sleep(rand()%10);
			printf("Child is created with PID= %d  PPID= %d\n", getpid(), getppid());
			exit(0);
		}
	}
	for(int i=0; i<n; i++)
	{
		retval=wait(&status);
		printf("child exit value is %d with PID= %d\n", (status>>8), retval);
	}
}
