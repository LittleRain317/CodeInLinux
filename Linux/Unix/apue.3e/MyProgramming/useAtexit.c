#include "../include/apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
	if (atexit(my_exit2) != 0)
		err_sys("can't register my_exit2");

	if (atexit(my_exit1) != 0)
	{
		err_sys("can't register my_exit1");
	}
	if (atexit(my_exit1) != 0)
	{
		err_sys("can't register my_exit1");
	}
	printf("main is done\n");
	exit(0);
}

static void my_exit1(void)
{
	printf("1 call\n");
}


static void my_exit2(void)
{
	printf("2 call\n");
}
