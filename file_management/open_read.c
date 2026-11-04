/**Writing some data into the file and then read and display*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
	int fd;
	char a[10], ch, i=0;
	if(argc != 2)
	{
		printf("Argument doest not provide properly\n");
		return 1;
	}
	fd = open(argv[1], O_CREAT|O_RDWR, 0660);
	printf("fd: %d\n", fd);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}
	printf("Successfully file is opened\n");
	if(write(fd, "Hello", 6) == 6)
        {
                printf("Successfully writen in file\n");
        }
	else
	{
		printf("Failed in writing\n");
		return 1;
	}
	lseek(fd, 0, SEEK_SET);
	while(1)
	{
		if((read(fd, &ch, 1)) == 1)
		{
			a[i++] = ch;

			if(ch == '\0')
			{
				break;
			}
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
