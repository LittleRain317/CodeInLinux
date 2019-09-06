#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN		128
#define QLEN 10

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif

extern int initserver(int, const struct sockaddr *, socklen_t, int);

void serve(int sockfd)
{
	int clfd;
	FILE *fp;
	char buf[BUFLEN];

	set_cloexec(sockfd);

	for (;;)
	{
		if ((clfd = accept(sockfd, NULL, NULL)) < 0)
		{
			syslog(LOG_ERR, "ruptimed: accept error:%s", strerror(errno));
			exit(1);
		}
		set_cloexec(sockfd);
		if ((fp = popen("/usr/bin/uptime", "r")) == NULL) 
		{
			sprintf(buf, "error : %s\n", strerror(errno));
			send(clfd, buf, strlen(buf), 0);
		}
		else
		{
			while (fgets(buf, BUFLEN, fp) != NULL)
			{
				send(clfd, buf, strlen(buf), 0);
			}
			pclose(fp);
		}
		close(clfd);
	}
}

int main(int argc, char *argv[])
{
	int sockfd;
	 struct sockaddr_in     servaddr;

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//IP地址设置成INADDR_ANY,让系统自动获取本机的IP地址。
	servaddr.sin_port = htons(9899);
		if ((sockfd = initserver(SOCK_STREAM, &servaddr, sizeof(struct sockaddr), 10)) >= 0)
		{
			serve(sockfd);
			exit(0);
		}
		else	
		{
			perror(NULL);
		}
	exit(1);
}
