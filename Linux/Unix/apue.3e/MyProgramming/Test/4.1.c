#include "../include/apue.h"

int main(int argc, char *argv[])
{
	int i;
	struct stat	buf;
	char *ptr;
	for (i = 1; i < argc; i++)
	{
		printf("%s: ", argv[i]);
		if (stat(argv[i], &buf) < 0) {
			err_ret("stat error");
			continue;
		}
		switch (buf.st_mode & S_IFMT)
		{
		case S_IFREG:
			ptr = "regular";
			break;
		case S_IFDIR:
			ptr = "directory";
			break;
		case S_IFCHR:
			ptr = "character special";
			break;
		case S_IFBLK:
			ptr = "block special";
			break;
		case S_IFIFO:
			ptr = "fifo";
			break;
		case S_IFLNK:
			ptr = "symbolic link";
			break;
		case S_IFSOCK:
			ptr = "socket";
			break;
		default:
			ptr = "** unknown mode **";
			break;
		}
		printf("%s\n", ptr);
	}
	return 0;
}
