#include "../include/apue.h"
  #include <sys/socket.h>
       #include <netinet/in.h>
       #include <arpa/inet.h>

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
	int sockfd;
	int client_sockfd;
    int len;
    struct sockaddr_in remote_addr; //服务器端网络地址结构体
    char buf[BUFSIZ];  //数据传送的缓冲区
    memset(&remote_addr,0,sizeof(remote_addr)); //数据初始化--清零
    remote_addr.sin_family=AF_INET; //设置为IP通信
    remote_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//服务器IP地址
    remote_addr.sin_port=htons(9899); //服务器端口号

		if ((sockfd = connect_retry(AF_INET, SOCK_STREAM, 0, &remote_addr, sizeof(struct sockaddr))) < 0) 
		{
		}
		else
		{
			print_uptime(sockfd);
			exit(0);
		}
}
