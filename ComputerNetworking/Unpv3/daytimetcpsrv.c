#include <unp/unp.h>
#include <pthread.h>
#include <time.h>
void* func(void* arg)
{
	int listenfd;
	struct sockaddr_in servaddr;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr =
//	inet_aton("127.0.0.1", &servaddr.sin_addr);
	htonl(INADDR_ANY);
	servaddr.sin_port = htons(9999);

	Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);

	int connfd = accept(listenfd, (SA*)NULL, NULL);
	if (connfd == -1)
	{
		perror("accept error");
		return (void*)-1;
	}
	printf("connfd:%d pid=%lu\n", connfd, pthread_self());
	close(connfd);
	return NULL;
}
int main(int argc, char *argv[])
{
	while (1)
	{
//		connfd = Accept(listenfd, (SA*)NULL, NULL);
		pthread_t pid;
		if (pthread_create(&pid, NULL, func, NULL) != 0)
		{
			perror("pthread_create error");
			return -1;
		}
	}
}
