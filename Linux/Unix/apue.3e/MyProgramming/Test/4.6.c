#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../include/apue.h"
int check(char* buff)
{
	for (size_t i = 0; i < 512; i++)
		if (buff[i] != 0)
			return 0;
	return 1;
}
int main(int argc, const char *argv[])
{
	if (argc != 3)
	{
		err_sys("usage: a.out <src> <dst>");
	}
	struct stat statbuf;
	if (stat(argv[1], &statbuf) < 0)
	{
		err_sys("stat error");
	}
	int fd = open(argv[1], O_RDONLY);
	int out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if (fd < 0)
	{
		err_sys("open error");
	}
	size_t size = 512; 
	char *buff = malloc(size);
	memset(buff, 0, size);
	size_t readsz = 0U;
	int flag = 0;
	if (statbuf.st_size >= statbuf.st_blocks * 512) 
		flag = 1;	
	int writeOk = 0;
	size_t countSeek = 0;
	for (size_t i = 0; i < statbuf.st_size;)
	{
		readsz  = ((size < statbuf.st_size - i) ? size : statbuf.st_size - i );
		if (read(fd, buff, readsz) != readsz)	
		{
			err_sys("read error");
			close(out);
			close(fd);
		}
		i += readsz;
		if (flag)
		{
			if (check(buff))
			{
				if (!writeOk)
				{
					countSeek += size;
				}
				else
				{
					countSeek = size;
				}
				if (lseek(out, countSeek, SEEK_END) < 0)
				{
					err_sys("lseek error");
				}
				writeOk = 0;
				continue;
			}
		}
		if (write(out, buff, readsz) != readsz)
		{
			err_sys("write error");
			close(out);
			close(fd);
		}
		else
		{
			writeOk = 1;	
		}
	}
	printf("done\n");
	return 0;
}
