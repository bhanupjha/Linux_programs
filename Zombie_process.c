#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int ret;
	ret=fork();
	if(ret==-1)
	{
		perror("fork");
		return 1;
	}
	if(ret==0)
	{//child process
		printf("P2: PID= %d PPID=%d \n",getpid(),getppid());
		sleep(10);
		printf("Child is exiting\n");
	}
	else
	{// parent process
		printf("P1: PID = %d PPID = %d \n", getpid(), getppid());
		while(1);
	}
}
