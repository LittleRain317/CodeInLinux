#include <fcntl.h>
#include <stdio.h>
int main()
{
	int i = open("../temp", O_RDONLY | O_CLOEXEC);
	int j = open("../temp", O_RDONLY);
	int k = open("../temp", O_EXCL);
	printf("%d %d\n", i, j);
	printf("O_CLOEXEC=%x\n", O_CLOEXEC);
	printf("result i = %d\n", fcntl(i, F_GETFD));
	printf("result j = %d\n", fcntl(j, F_GETFD));
	
	void *p = NULL;
	return 0;
}
