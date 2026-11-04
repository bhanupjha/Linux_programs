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
	for(i=1; i<100000; i++)
                for(j=1; j<90000; j++);
	printf("I am exiting from the Handler\n");
}
int main()
{
	struct sigaction s;
	s.sa_handler = myHandler;
	sigemptyset(&s.sa_mask);
	s.sa_flags = SA_NODEFER;
	sigaction(SIGINT, &s, NULL);
	while(1);
}

