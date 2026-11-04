#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void my_isr(int n)
{
	printf("In ISR...\n");
	sleep(10);
	printf("Out ISR...\n");
}

int main()
{
	struct sigaction v;
	v.sa_handler = my_isr;
	sigemptyset(&v.sa_mask);
	v.sa_flags = SA_RESETHAND;

	sigaction(SIGQUIT, &v, NULL);
	while(1);
}
