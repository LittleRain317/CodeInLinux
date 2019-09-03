#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{

	time_t t;
	if (time(&t) == -1)
	{
		printf("error time\n");
	}
	struct tm* tm = localtime(&t);
	if (NULL == tm)
	{
		printf("error gmtime\n");
	}
	char buff[1024] = { 0 };
//	2019年 09月 03日 星期二 15:41:06 CST
	if (strftime(buff, 1024, "%Y年 %m月 %d日 星期%w %X %Z", tm) == 0)
	{
		printf("error strftime\n");
	}
	else
		printf("%s\n", buff);
	return 0;
}
