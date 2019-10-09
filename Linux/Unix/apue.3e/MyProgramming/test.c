#include <fcntl.h>
//#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int a = 0x12;
	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		perror("open error");
	if (write(fd, &a, sizeof(a)) != sizeof(a))
		perror("write error");
	close(fd);
	return 0;
}
