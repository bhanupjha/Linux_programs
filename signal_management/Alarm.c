#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int  main()
{
	int i=1;
	printf("Hii...\n");
	alarm(5);
	printf("Hello...\n");
	while(1)
	{
		printf("i = %d\n", i++);
		sleep(1);
	}
}
