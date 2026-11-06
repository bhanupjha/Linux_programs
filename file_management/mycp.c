// WAP to design the user defined CP copmmand which should work same like cp command
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fs, fd, n;
	char a[100];
	if(argc != 3)
	{
		printf("Argument does not provide  properly\n");
		return 1;
	}
	fs = open(argv[1], O_RDONLY);
	if(fs<0)
	{
		perror("Open source");
		return 1;
	}
//	printf("fs: %d\n", fs);
	fd = open(argv[2], O_CREAT|O_RDWR|O_TRUNC, 0660);
//	printf("fd: %d\n", fd);
	if(fd<0)
	{
		perror("Open destination");
		return 1;
	}
	while((n = read(fs, a, sizeof(a))) > 0)
	{
		if(write(fd, a, n) != n)
		{
			perror("write");
			close(fs);
			close(fd);
			return 1;
		}
	}
	
	if(n < 0)
	{
		perror("read");
	}
	else
		printf("File copied successfully\n");

	close(fs);
	close(fd);

	return 0;
	
}
