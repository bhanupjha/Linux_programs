#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	int ret;
	ret=fork();
	if(ret==-1)
	{
		printf("Fork");
		return 1;
	}
	if(ret==0)
	{ // child process
		printf("P2: PID= %d PPID= %d\n", getpid(), getppid());
		sleep(20);
		printf("Child is exiting\n");
		exit(10);
	}
	else
	{ // parent process
		printf("P1: PID= %d PPID= %d\n", getpid(), getppid());
		int status, retval;
		retval=wait(&status);
		printf("Exit status of child is with pid=  %d is %d\n", retval, ((status>>8)&0XFF));
		while(1);
	}
}
