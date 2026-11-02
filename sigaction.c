#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void myHandler1(int sigtype)
{
	printf("I am in sig Handler1\n");
}

void myHandler2(int sigtype)
{
	printf("I am in sig Handler2\n");
}

int main()
{
	struct sigaction s;
	s.sa_handler = myHandler1; //
//	s.sa_handler = SIG_IGN;   // 
	sigemptyset(&s.sa_mask);
	s.sa_flags=0;
	sigaction(SIGINT, &s, NULL);
	s.sa_handler = myHandler2;
	sigaction(SIGALRM, &s, NULL);
	alarm(5);
	while(1);
}
