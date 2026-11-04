#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	int i;
	printf("Hii..\n");
	i=alarm(10);
	printf("Return value of alarm(10)=%d\n", i);
	sleep(3);
	i=alarm(4);
        printf("Return value of alarm(4)=%d\n", i);
	sleep(2);
	i=alarm(6);
        printf("Return value of alarm(0)=%d\n", i);
	printf("Hello..\n");
}
