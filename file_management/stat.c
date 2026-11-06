#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>


int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Argument doesnot provide properly\n");
		return 1;
	}

	struct stat p;
	if(stat(argv[1], &p) == -1)
	{
		perror("stat");
		return 1;
	}
	printf("Device ID: %ld\n", p.st_dev);
	printf("Inode No: %ld\n", p.st_ino);
	printf("File Type: %d\n", p.st_mode);
	printf("Hard Link: %ld\n", p.st_nlink);
	printf("User Id: %d\n", p.st_uid);
	printf("Group Id: %d\n", p.st_gid);
	printf("Device ID [SPEC file]: %ld\n", p.st_rdev);
	printf("Size: %ld\n", p.st_size);
	printf("Block size: %ld\n", p.st_blksize);
	printf("Blocks: %ld\n", p.st_blocks);
	struct tm *t;
	char a[100];
	t=localtime(&p.st_atime);
	if(t==NULL)
	{
		perror("localtime");
		return 1;
	}
	if(strftime(a, sizeof(a), "%F %T", t) == 0)
	{
		perror("strftime");
		return 1;
	}
	printf("Last Access: %s %ld\n", a, p.st_atim.tv_nsec);
/*	printf("Last Modification: %ld\n", p->st_mtime);
	printf("Last status change: %ld\n", p->st_ctime);*/
}
