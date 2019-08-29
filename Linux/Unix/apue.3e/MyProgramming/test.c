#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define ___ 0000
#define __x 0001
#define _w_ 0002
#define _wx 0003
#define r__ 0004
#define r_x 0005
#define rw_ 0006
#define rwx 0007
#define _24k(length, path) _24ksb(length, rw_, path)
void* _24ksb(size_t length, int mode, char *path)
{
	int result = 0;
	switch (mode)
	{
		case ___:
			result = PROT_NONE;
			break;
		case __x:
			result = PROT_EXEC;
			break;
		case _w_:
			result = PROT_WRITE;
			break;
		case _wx:
			result = PROT_EXEC | PROT_WRITE;
			break;
		case r__:
			result = PROT_READ;
			break;
		case r_x:
			result = PROT_EXEC | PROT_READ;
			break;
		case rw_:
			result = PROT_WRITE | PROT_READ;
			break;
		case rwx:
			result = PROT_EXEC | PROT_READ | PROT_WRITE;
			break;
	}
	char temp[1024] = "./XXXXXX";
	int fd = mkstemp(temp);
	memcpy(path, temp, strlen(temp));
	char buff[4096] = { 0 };
	size_t sz = 0U;
	for (size_t i = 0; i != length; i += sz)
	{
		sz = (length - i > 4096 ? 4096 : length -i);
		write(fd, buff, sz);
	}
	return mmap(NULL, length, result, MAP_SHARED, fd, 0); 
}
#include <stdio.h>
int main()
{
	char buff[1024] = { 0 };
	void* test = _24k(30, buff);
	*(int*)test = 400;
	printf("缓冲文件:%s\n", buff);
	//unlink(buff);
	return 0;
}
