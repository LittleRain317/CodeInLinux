#include <sys/stat.h>
#include <stdio.h>
int main()
{
	if (mkdir("", S_IRWXU) < 0)
	{
		printf("error\n");
		return -1;
	}
	return 0;
}
