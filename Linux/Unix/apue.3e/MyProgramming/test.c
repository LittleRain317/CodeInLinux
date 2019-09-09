#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	printf("%lu\n", (unsigned long)sysconf(_SC_THREAD_STACK_MIN));
	return 0;
}
