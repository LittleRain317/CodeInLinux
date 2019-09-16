#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("user=%s\n", getlogin());
	return 0;
}
