#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myHandler(int signum)
{
	printf("Alarm time period is expired\n");
}

int main()
{
	printf("Registering the user defined action for sigint signal\n");
	signal(SIGALRM, myHandler);
	alarm(10);  // set alarm --- send the SIGALRM to the process after 10 sec
	while(1);
}
