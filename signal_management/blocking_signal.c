// sigaddset -> specified signal is blocked during the execution later unblock it after execution of handler.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void myHandler(int sigtype)
{
	unsigned int i, j;
	printf("I am in sig Handler\n");
	for(i=1; i<100000; i++)
		for(j=1; j<90000; j++);
	for(i=1; i<100000; i++)
                for(j=1; j<90000; j++);
	printf("I am exiting from the Handler\n");
}
int main()
{
	struct sigaction s;
	s.sa_handler = myHandler;
	sigemptyset(&s.sa_mask);
	sigaddset(&s.sa_mask, SIGQUIT);
	sigaddset(&s.sa_mask, SIGHUP);

	s.sa_flags = 0;
	sigaction(SIGINT, &s, NULL);
	while(1);
}

