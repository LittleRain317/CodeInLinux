#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main()
{
	char str[1024];
	scanf("%s", str);
	printf("%s\n", str);
	return 0;
}
