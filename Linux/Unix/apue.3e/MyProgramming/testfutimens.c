#include "../include/apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int i, fd;
	struct stat statbuf;
	struct timespec times[2];
	for (i = 1; i < argc; i++)
	{
		if (stat(argv[i], &statbuf) < 0) 
		{
			err_ret("%s: stat error", argv[i]);
			continue;
		}
		if ((fd = open(argv[i], O_RDONLY) < 0))
		{
			err_ret("%s: open error", argv[i]);
			continue;
		}
		times[0].tv_sec = 200000;
		times[0].tv_nsec = 300000;
		times[1].tv_sec = 5000000;
		times[1].tv_nsec = 4000000;
		//if (futimens(fd, times) < 0)
		if (utimensat(AT_FDCWD, argv[i], times, 0) < 0)
		{
			err_ret("%s: futimens error", argv[i]);
		}
		close(fd);
	}
	return 0;
}
