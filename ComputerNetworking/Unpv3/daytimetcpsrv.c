#include <unp/unp.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];
	time_t ticks;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(9999);

	Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);
	size_t count = 0;
	while (1)
	{
		connfd = Accept(listenfd, (SA*)NULL, NULL);
		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s", ctime(&ticks));
		while (count < strlen(buff))
		{
			Write(connfd, &buff[count], 1);
			count++;
		}
		Close(connfd);
		count = 0;
	}
}
