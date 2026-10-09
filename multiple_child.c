#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int n, ret;
	if(argc!=2)
	{
		printf("Arguments doesn't provide properly\n");
		return 1;
	}
	n = atoi(argv[1]);   // convert ascii to integer
	for(int i=0; i<n; i++)
	{
		ret=fork();
		if(ret==0)
       		{
                	printf("child is created with PID= %d  PPID= %d\n", getpid(), getppid());
			exit(0);
        	}
	}
}
