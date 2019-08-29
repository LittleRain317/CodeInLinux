#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	int fd = 0;
	if ((fd = creat("Zero", S_IRWXU)) < 0)
	{
		fprintf(stderr, "creat error\n");	
		return -1;
	}
	char buf[] = "hello world";
 	if (write(fd, buf, sizeof(buf) / sizeof(char)) != (sizeof(buf) / sizeof(char)))
	{
		fprintf(stderr, "write error\n");
		close(fd);
		return -1;
	}
	if (lseek(fd, 4096 * 3, SEEK_END) == -1)
	{
		fprintf(stderr, "lseek error\n");
		close(fd);
		return -1;
	}
	if (write(fd, buf, sizeof(buf) / sizeof(char)) != (sizeof(buf) / sizeof(char)))
	{
		fprintf(stderr, "write error\n");
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}
