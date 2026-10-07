/*Maximum how many times Hello,Hi,Exiting is printed*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	printf("Hello\n");
	fork();
	printf("Hi\n");
	fork();
	printf("Exiting\n");
}
