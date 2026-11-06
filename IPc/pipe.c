// ps -el | wc -l
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int a[2];
	if(pipe(a) == -1)
	{
		perror("pipe");
		return 1;
	}
	int ret = fork();
	if(ret == -1)
	{
		perror("process");
		return 1;
	}
	if(ret>0)
	{ // parent process
		close(a[0]);
		dup2(a[1], 1);
		execlp("ps", "ps", "-e", "-l", NULL);
	}
	else
	{ // child code
		close(a[1]);
		dup2(a[0], 0);
		execlp("wc", "wc", "-l", NULL);
	}
}
