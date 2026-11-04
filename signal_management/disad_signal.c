// when same signal is executing the handler if come again it will put on hold till current execution completed.
// different signal came then then serve the recent one .
// like if SIGQUIT came it is executing again SIGQUIT came it will go on hold.
// if SIGINT executing SIGQUIT came then SIGQUIT ISR served then SIGINT ISR.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void my_isr(int n)
{
	printf("\nIn ISR...%d\n", n);
	sleep(10);
	printf("\nOut..%d\n", n);
}
int main()
{
	signal(SIGINT, my_isr);
	signal(SIGQUIT, my_isr);
	while(1);
}
