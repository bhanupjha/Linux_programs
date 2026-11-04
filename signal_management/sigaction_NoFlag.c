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
		// SIGCHILD disturbs parent on child suspend, resume, terminate
		v.sa_flags = 0;
		sigemptyset(&v.sa_mask);
		sigaction(17, &v, NULL);
		while(1);
	}
}
