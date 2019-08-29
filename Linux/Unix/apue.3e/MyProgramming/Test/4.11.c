#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
extern int errno;
static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;
static int myftw(char *pathname)
{
	DIR* dp = NULL;
	struct dirent	* dirp = NULL;
	if ((dp = opendir(pathname)) == NULL)
	{
		perror("error for opendir\n");
		return -1;
	}
	struct stat statbuf;
	if (chdir(pathname) < 0)
	{
		perror("error for chdir\n");
		return -1;
	}
	while ((dirp = readdir(dp)))
	{
		if (lstat(dirp->d_name, &statbuf) < 0)
		{
			perror("error for lstat\n");
			return -1;
		}
		if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
			continue;
		switch (statbuf.st_mode & S_IFMT)
		{
		case S_IFSOCK:
			nsock++;
//static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;
			break;
		case S_IFLNK:
			nslink++;
			break;
		case S_IFREG:
			nreg++;
			break;
		case S_IFBLK :
			nblk++;
			break;
		case S_IFDIR:
			ndir++;
			myftw(dirp->d_name);
			break;
		case S_IFCHR:
			nchr++;
			break;
		case S_IFIFO:
			nfifo++;
			break;
		}
	}
	if (chdir("../") < 0)
	{
		printf("chdir error\n");
	}
	closedir(dp);
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: ftw <starting-pathname>");
		return -1;
	}
	myftw(argv[1]);
	ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
	if (ntot == 0)
		ntot = 1;
	printf("regular files = %7ld, %5.2f %%\n", nreg, nreg * 100.0/ntot);
	printf("directories   = %7ld, %5.2f %%\n", ndir, ndir * 100.0/ntot);
	printf("block sepcial = %7ld, %5.2f %%\n", nblk, nblk * 100.0/ntot);
	printf("char special  = %7ld, %5.2f %%\n", nchr, nchr * 100.0/ntot);
	printf("FIFOs special = %7ld, %5.2f %%\n", nfifo, nfifo * 100.0/ntot);
	printf("symbolic links= %7ld, %5.2f %%\n", nslink, nslink * 100.0/ntot);
	printf("socket        = %7ld, %5.2f %%\n", nsock, nsock * 100.0/ntot);
	return 0;
}

