#include "../include/apue.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdint.h>

#define COPYINCR (1024 * 1024 * 1024)

int main(int argc, char *argv[])
{
	struct stat statbuf;
	if (stat("tempfile", &statbuf) < 0)
	{
		printf("stat error\n");
		return -1;
	}
	int fd = open("tempfile", O_RDWR);
	if (fd < 0)
	{
		printf("fd error\n");
		return -1;
	}
	void* src = mmap(0, statbuf.st_size / sysconf(_SC_PAGESIZE) * sysconf(_SC_PAGESIZE), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	char buff[] = "bzsefwetqw";
	*(int64_t*)src = 0xffabcfcc;
	printf("%lx\n", *(int64_t*)src);
	printf("%d\n", sizeof(int));
	return 0;
}
