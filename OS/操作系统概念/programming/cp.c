#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
int IsExist(const char* fileName) //-1存在 -2不存在 0及0以上错误 -3目录
{
	extern int errno;
	DIR* dir = opendir("./");
	if (NULL == dir)
	{
		return errno;
	}
	struct dirent* each = NULL;
	while ((each = readdir(dir)))
	{
		
		if (strncmp(each->d_name, fileName, strlen(each->d_name)) == 0)
		{
			if (each->d_type ==  DT_DIR)
			{
				closedir(dir);
				return -3;
			}
			else 
			{
				closedir(dir);
				return -1;
			}
		}
	}
	closedir(dir);
	return -2;

}

int main()
{
	char input[100] = { 0 };
	char output[100] = { 0 };
	printf("input file:");
	scanf("%100s", input);
	printf("output file:");
	scanf("%100s", output);
	int errorInput = IsExist(input);
	if (errorInput > 0)
	{
		perror("exist error");
		return -1;
	}
	if (errorInput == -3)
	{
		fprintf(stderr, "src is dir\n");
		return -1;	
	}
	if (errorInput == -2)
	{
		fprintf(stderr, "src must be exist\n");
		return -1;
	}
	int errorOutput = IsExist(output);
	if (errorOutput > 0)
	{
		perror("exist error");
		return -1;
	}
	if (errorOutput == -3)
	{
		fprintf(stderr, "dst is dir\n");
		return -1;	
	}
	if (errorOutput == -1)
	{
		fprintf(stderr, "dst is exist\n");
		return -1;
	}
	struct stat temp;
	if (stat(input, &temp) < 0)
	{
		perror("stat error");
		return -1;
	}
	int mode = temp.st_mode & 0777;    
	int fdout = creat(output, mode);
	if (fdout == 0)
	{
		perror("creat error");
		return -1;
	}
	int fdin = open(input, O_RDONLY);
	if (fdin == 0)
	{
		perror("open error");
		return -1;

	}
	char buff[1024] = { 0 };
	int result = 0;
	
	while ((result = read(fdin, buff, 1024)))
	{
		buff[result] = 0;
		if (result == -1)
		{
			perror("read error");
			close(fdin);
			close(fdout);
			if (unlink(output) == -1)
			{
				perror("unlink error");
				return -1;
			}
			return -1;
		}
		write(fdout, buff, strlen(buff));	
	}
	close(fdin);
	close(fdout);
	printf("complete\n");
	return 0;
}
