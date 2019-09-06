#include <stdio.h>
#include <arpa/inet.h>
int main()
{
	char src[] = "139.196.84.233";
	char dst[32] = { 0 };
	inet_pton(AF_INET, src, dst);
	printf("dst=%s\n", dst);
	return 0;
}
