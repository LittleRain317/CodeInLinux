#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>       /* basic system data types */
#include<sys/socket.h>      /* basic socket definitions */
#include<netinet/in.h>      /* sockaddr_in{} and other Internet defns */
#include<arpa/inet.h>       /* inet(3) functions */
#include<sys/epoll.h>       /* epoll function */
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
 
 
int main(int argc,char*argv[])
{
    int listenfd,connfd;
    struct sockaddr_in cliaddr,servaddr;
    int queuelen=5;
 
    if(argc!=2){
        puts("usage# ./aworker listenqueuelen");
        exit(0);
    }   
    queuelen=atoi(argv[1]);
 
    listenfd = socket(AF_INET,SOCK_STREAM,0);
 
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9998);
    
    bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    
    listen(listenfd,queuelen);
//    sleep(10); //将这个注释，会出现另一种情况哟~~  
    while(1)
    {
        connfd = accept(listenfd,NULL,0);
		struct sockaddr_in local, peer;
		socklen_t localLength = sizeof(local), peerLength = sizeof(peer);
		bzero(&local, sizeof(local));
		bzero(&peer, sizeof(perror));
		char buff[2][16] = { 0 };
		getsockname(connfd, (struct sockaddr *)&local, &localLength);
		getpeername(connfd, (struct sockaddr *)&peer, &peerLength);
		printf("local-ip:%s local-port:%d local-length:%u\n", inet_ntop(AF_INET, &local.sin_addr, buff[0], 16), 
				local.sin_port, localLength);
		printf("peer-ip:%s peer-port:%d peer-length:%u\n", inet_ntop(AF_INET, &peer.sin_addr, buff[1], 16),
				peer.sin_port, peerLength);
        if(connfd == -1)
        {
            perror("accept error");
            continue;
        }
        puts("new connection...");
    }
    return 0;
}
