#include <unp/unp.h>

void str_echo(int sockfd)
{
	ssize_t n;
	char buf[MAXLINE];
again:
	while ((n = readline(sockfd, buf, MAXLINE)) > 0)
		Writen(sockfd, buf, n);
	if (n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		err_sys("str_echo error");
}

void sig_chld(int signo)
{
	pid_t pid;
	int stat;
	pid = wait(&stat);
	printf("child %d terminated\n", pid);
	return;
}
int main(int argc, char * argv[])
{
	if (signal(SIGCHLD, sig_chld) == SIG_ERR)
	{
		perror("signal error");
		return -1;
	}
	int listenfd, connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);
	while (1)
	{
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *)&cliaddr, &clilen);
		if ((childpid = fork()) == 0)
		{
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
}
