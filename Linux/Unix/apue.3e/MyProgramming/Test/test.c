#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
int main(void)
{
	if (opendir("test.c") == NULL)
	{
		printf("错误\n");
	}
	return 0;
}
