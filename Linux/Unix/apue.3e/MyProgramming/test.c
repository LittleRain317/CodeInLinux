#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
int main(void)
{
	DIR *dp = opendir(".");
	struct dirent *dirp;
	if (dp == NULL)
		return -1;
	long int temp = telldir(dp);
	int i = 0;
	while ((dirp = readdir(dp)) != NULL)
	{
		printf("name=%s\n", dirp->d_name);


	printf("结束%ld\n", telldir(dp));
	}

	printf("结束%ld\n", telldir(dp));
	readdir(dp);
	printf("结束%ld\n", telldir(dp));
	closedir(dp);
//	printf("uid=%u gid=%u euid=%u egid=%u\n", getuid(), getgid(), geteuid(), getegid());
	return 0;
}
