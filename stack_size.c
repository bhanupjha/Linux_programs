#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>
void f1(int n)
{
	char str[1000000];
	printf("f1...%d\n",n);
	if(n<20)
		f1(n+1);
	printf("returning from f1\n");
return;
}


int main()
{
	struct rlimit var;
	if(getrlimit(RLIMIT_STACK,&var)==-1)//requests to kernel, to fetch the stack size of this process 
	{
		perror("getrlimit"); 
		exit(0);
	}
	var.rlim_cur*=3;
	if(setrlimit(RLIMIT_STACK,&var)==-1)//Requests the kernel, to modify the stack limit of THIS PROCESS to the values in var.
	{
		perror("setrlimit");  
		exit(0);
	}	
        printf("%u\n%u\n",var.rlim_cur,var.rlim_max);

	f1(1);
return 0;
}
