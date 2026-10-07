#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int ret;
	static int i=10;
	ret=fork();
	if(ret==-1)
	{
		perror("fork");
		return 1;
	}
	if(ret==0)
	{//child process
		printf("P2: PID= %d PPID=%d \n",getpid(),getppid());
		i+=10;
		printf("P2:i=%d\n",i);
	}
	else
	{// parent process
		sleep(10);
		printf("P1: PID = %d PPID = %d \n", getpid(), getppid());
		printf("P1: i = %d\n", i);
	}
}
