#include <stdio.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int r, sig;
	if(argc!=3)
	{
		printf("Usage:./mykill pid signum\n");
		return;
	}

	sig = atoi(argv[2]);
	r = kill(atoi(argv[1]), sig);

	if(sig!=0)
	{
		if(r==-1)
		{
			perror("Kill");
		}
	}
	else
	{
		if(r==0)
		{
			printf("Process exist we can send signal\n");
		}
		else
		{
			if(errno == EPERM)
			{
				printf("Process exists, No permission to send signal\n");
			}
			else if(errno == ESRCH)
			{
				printf("process does not exist\n");
			}
			else
			{
				perror("Kill");
			}
		}
	}
}
