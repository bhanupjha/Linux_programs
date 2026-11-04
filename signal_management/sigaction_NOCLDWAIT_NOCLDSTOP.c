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
		// SIGCHLD will not disturb parent for suspend and resume
		// and no need to write wait in ISR to remove child from zombie
		v.sa_flags = SA_NOCLDSTOP|SA_NOCLDWAIT;
		sigemptyset(&v.sa_mask);
		sigaction(17, &v, NULL);
		while(1);
	}
}
