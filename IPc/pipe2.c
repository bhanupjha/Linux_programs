// ps -el | grep pts | wc -l

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
	int p1[2];
	int p2[2];

	if(pipe(p1)  == -1)
	{
		perror("pipe1");
		return 1;
	}
	if(pipe(p2) == -1)
	{
		perror("pip2");
		return 1;
	}
	
	int ret = fork();
	if(ret == -1)
	{
		perror("fork");
		return 1;
	}
	if(ret==0)
	{ // child 1 code
	  	dup2(p1[1], 1);
		close(p1[0]);
		close(p1[1]);
		close(p2[0]);
		close(p2[1]);
		execlp("ps", "ps", "-e", "-l", NULL);
		perror("ps");
		return 1;
	}
	int ret2 = fork();
	if(ret2 == -1)
	{
		perror("fork");
		return 1;
	}
	if(ret2 == 0)
	{// child 2 code
	 	dup2(p1[0], 0);
		dup2(p2[1], 1);
		close(p1[1]);
		close(p1[0]);
                close(p2[0]);
                close(p2[1]);
		execlp("grep", "grep", "pts", NULL);
		perror("grep");
		return 1;
	}
	
	// parent process
	dup2(p2[0], 0);
	close(p1[0]);
	close(p1[1]);
	close(p2[0]);
	close(p2[1]);
	execlp("wc", "wc", "-l", NULL);
	perror("wc");
	return 1;
	

}
