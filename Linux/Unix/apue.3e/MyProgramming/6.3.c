#include <stdio.h>
#include <sys/utsname.h>
#define _GNU_SOURCE
int main()
{
	struct utsname name;
	if (uname(&name) != -1)
	{
		printf("sysname = %s\n", name.sysname);
		printf("nodename=%s\n", name.nodename);
		printf("release= %s\n", name.release);
		printf("version= %s\n", name.version);
		printf("machine= %s\n", name.machine);
#ifdef _GNU_SOURCE
		printf("domainname= %s\n", name.__domainname);
#endif
	}
	else	printf("error\n");
	return 0;
}
