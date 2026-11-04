#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Hello....%d\n", getpid());
	sleep(10);
	raise(SIGSEGV);  // or raise(11)
}
