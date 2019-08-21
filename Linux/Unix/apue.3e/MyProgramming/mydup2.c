#include <unistd.h>
int mydup2(int fd, int fd2)
{
	if (fd < 0 || fd > 1024)
		return -1;
	if (fd2 < 0 || fd2 > 1024)
		return -1;
	if (fd2 == fd)
	{
		return fd2;
	}
	close(fd2);
	int newfd = 0;
	while ((newfd = dup(fd)) != fd2)
	{
		close(newfd);
	}
	return fd2;
}
