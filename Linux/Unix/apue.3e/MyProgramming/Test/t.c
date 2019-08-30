#include <unistd.h>
#include <stdio.h>
int main()
{
	int it = 0x64636261;
	char buff[4] = { 0 };
	read(STDIN_FILENO, &buff, 4);
	printf("it=%d\n", it);
	write(STDOUT_FILENO, &it, 4);
	printf("sizeof(int)=%lu\n", sizeof(int));
	return 0;
}
