#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("argument doesnot provide properly\n");
		return 1;
	}
	if(mkfifo(argv[1], 0664)==-1)
	{
		perror("fifo");
		if (errno != EEXIST)
			return 1;
	}
	printf("Fifo is available for use\n");
	int fd = open(argv[1], O_WRONLY);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}
	printf("fd: %d\n", fd);
	char a[100];
	char ch, i=0;
	while(1)
	{
		if(read(fd, &ch, 1) == 1)
		{
			a[i++] = ch;
			if(ch == '\0')
				break;
		}
		else
		{
			perror("read");
			return 1;
		}
	}
	printf("Read data is %s\n", a);

	close(fd);
}
