// floating poin exception
// dividing by 0 -> SIGFPE
#include <stdio.h>

int main()
{
	int a=5, b=0, c;
	c=a/b;
	printf("%d\n", c);
}
