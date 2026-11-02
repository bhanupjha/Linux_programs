#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("pid=%d\n", getpid());
	if((execlp("ls", "ls", "-a", "-l", NULL))==-1)
	{
		perror("execlp");
		exit(1);
	}
	printf("Exiting from the process\n");
}
