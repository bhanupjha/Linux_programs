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
        signal(SIGINT, myHandler);
        sleep(10);
}

