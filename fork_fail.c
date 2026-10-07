#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int ret;
	ret = fork();
	if(ret==-1)
	{
		perror("fork");
		return 1;
	}
	if(ret>0)
	{
		printf("P1: PID = %d PPID = %d\n", getpid(), getppid());
	}
	else
	{
		printf("P2: PID = %d PPID = %d\n", getpid(), getppid());
	}
}
