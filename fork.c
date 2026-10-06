// Maxm how many times hello and existing will print
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("Hello\n");
	fork();
	printf("Existing\n");
}
