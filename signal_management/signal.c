#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myHandler(int signum)
{
        printf("signum=%d\n",signum);
}
int main()
{
        printf("registring the ignore act for sigint signal\n");
        signal(SIGINT, SIG_IGN);
        sleep(10);
	printf("registering the user defined act for sigint signal\n");
	signal(SIGINT, myHandler);
	sleep(10);
	printf("Registering the default act for signint signal\n");
	signal(SIGINT, SIG_DFL);
	while(1);
}

