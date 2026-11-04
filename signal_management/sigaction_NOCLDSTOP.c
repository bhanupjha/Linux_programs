#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void my_isr(int n)
{
	printf("IN ISR... %d\n", n);
	printf("Out ISR..\n");
}

int main()
{
	if(fork() == 0)
	{
		printf("In child...%d\n", getpid());
		while(1);
	}
	else
	{
		struct sigaction v;
		v.sa_handler = my_isr;
		// SIGCHILD will not disturbs parent on child suspend and resume
		v.sa_flags = SA_NOCLDSTOP;
		sigemptyset(&v.sa_mask);
		sigaction(17, &v, NULL);
		while(1);
	}
}
