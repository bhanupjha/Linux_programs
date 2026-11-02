#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *a[]={"ls", "-a", "-l", NULL};
	if((execvp("ls", a))==-1)
	{
		perror("execvp");
		exit(1);
	}
}
