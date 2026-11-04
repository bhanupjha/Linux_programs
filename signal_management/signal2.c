#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int c;

void my_isr(int sig)
{
	printf("\n In ISR...%d\n", sig);
	if(sig == 2)
	{
		printf("%d: SIGINT signal is delivered\n", sig);
		printf("Square of %d is %d\n", c, c*c);
	}
	else if(sig == 3)
	{
		printf("%d: SIGQUIT signal is delivered\n", sig);
                printf("Cube of %d is %d\n", c, c*c*c);
	}
}
int main()
{
	signal(SIGINT, my_isr);
	signal(SIGQUIT, my_isr);

	printf("PID: %d\n", getpid());
	printf("Enter the number:\n");
	scanf("%d", &c);

	pause();
	pause();
}
