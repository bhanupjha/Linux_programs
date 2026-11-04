// terminating infinetly running program
// ctrl+\ -> SIGQUIT  signal

#include <stdio.h>

int main()
{
	printf("Hi\n");
	while(1);
}
