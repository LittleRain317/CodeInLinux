#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
int main(int argc, char * argv[])
{
	struct temp
	{
		int a;
	};
	struct temp a;
	const struct temp b;
	a = b;
	printf("%d\n", b.a);
	return 0;
}
