#include "../include/apue.h"
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>

#define BUFLEN 		128
extern int connect_retry(int, int, int, const struct sockaddr *, socklen_t);

void print_uptime(int sockfd)
{
	int n;
	char buf[BUFLEN];

	while (( n = recv(sockfd, buf, BUFLEN, 0)) > 0)
	{
		write(STDOUT_FILENO, buf, n);
	}
	if (n < 0)
	{
		err_sys("recv error");
	}
}

int main(int argc, char *argv[])
{
	int sockfd = 0;	
	struct sockaddr_in     servaddr;
	  memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//IP地址设置成INADDR_ANY,让系统自动获取本机的IP地址。
		if ((sockfd = connect_retry(AF_INET, SOCK_STREAM, 0, &servaddr, sizeof(struct addrinfo))) < 0) 
		{
			perror(NULL);
		}
		else
		{
			print_uptime(sockfd);
			exit(0);
		}
}
