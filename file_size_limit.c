#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

int main()
{
	struct rlimit limit;
	int fd;
	int byte_wr;

	const char *data = "111123132132132132132132132131321321321321321321111111111321212313211321321";

	limit.rlim_cur = 50;
	limit.rlim_max = 50;

	if(setrlimit(RLIMIT_FSIZE, &limit) == -1)
	{
		perror("setrlimit");
		exit(0);
	}

	printf("Successfully set the hard limit and soft limit\n");

	fd = open("test_limit.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd < 0)
	{
		perror("Openfile");
		exit(0);
	}

	byte_wr = write(fd, data, strlen(data));
	if(byte_wr < 0)
	{
		perror("write");
		exit(0);
	}
	else
	{
		printf("Byte successfuully written");
	}
	close(fd);
	return 0;
}
