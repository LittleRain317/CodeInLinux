#include <stdio.h>
#include <unp/unp.h>
void str_cli(FILE* fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];
	while (Fgets(sendline, MAXLINE, fp) != NULL)
	{
		Writen(sockfd, sendline, strlen(sendline));
		//if (readline(sockfd, recvline, MAXLINE) == 0)
		if (read(sockfd, recvline, MAXLINE) == 0)
		{
			perror("readline error");
			err_quit("str_cli: server terminated prematurely");
		}
		Fputs(recvline, stdout);
	}
}
