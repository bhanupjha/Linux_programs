// send the signal through another terminal

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main()
{
	signal(1, SIG_IGN);
	while(1);
}
