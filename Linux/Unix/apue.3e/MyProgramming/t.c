#include <unistd.h>
#include <stdio.h>
int main()
{
	char buf[1024] = { 0 };
	fgets(buf, 1024, stdin);
	printf("buf=%s\n", buf);
	printf("pid=%d ppid=%d pgid=%d\n", getpid(), getppid(), getpgrp());
	return 0;
}
