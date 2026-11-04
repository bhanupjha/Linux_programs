// WAP to design the user defined CP copmmand which should work same like cp command
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fs, fd;
	char a[100];
	char ch, i=0;
	if(argc != 3)
	{
		printf("Argument does not provide  properly\n");
		return 1;
	}
	fs = open(argv[1], O_RDONLY, 0400);
	printf("fs: %d\n", fs);
	while(1)
	{
		if((read(fs, &ch, 1))==1)
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
	fd = open(argv[2], O_CREAT|O_RDWR, 0660);
        printf("fd: %d\n", fd);
	if((write(fd, a, 6)) == 6)
	{
		printf("Successfully written\n");
	}
	else
	{
		printf("Read fail\n");
		return 1;
	}

	
}
