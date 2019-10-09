#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		perror("oepn error");
	int num = 0;
	if (read(fd, &num, sizeof(int)) != sizeof(int))
		perror("read error");
	printf("%#x\n", num);
	close(fd);
	return 0;
}
