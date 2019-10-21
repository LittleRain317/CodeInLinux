#include <stdio.h>
#include <sys/wait.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int sockfd;
    int rc; 
    int cpid;
    struct sockaddr_in servaddr;
    
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET,"139.196.84.233",&servaddr.sin_addr);
    servaddr.sin_port = htons(9998);
    
    for(int i=0;i<20;i++)
    {   
            sockfd = socket(AF_INET,SOCK_STREAM,0);
            rc = connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
            if(rc == -1) 
            {   
                perror("connect error");
                exit(0);
            }   
            printf("pid#%d connected...\n",getpid());
struct sockaddr_in local, peer;
		socklen_t localLength = sizeof(local), peerLength = sizeof(peer);
		bzero(&local, sizeof(local));
		bzero(&peer, sizeof(perror));
		char buff[2][16] = { 0 };
		getsockname(sockfd, (struct sockaddr *)&local, &localLength);
		getpeername(sockfd, (struct sockaddr *)&peer, &peerLength);
		printf("local-ip:%s local-port:%d local-length:%u\n", inet_ntop(AF_INET, &local.sin_addr, buff[0], 16), 
				local.sin_port, localLength);
		printf("peer-ip:%s peer-port:%d peer-length:%u\n", inet_ntop(AF_INET, &peer.sin_addr, buff[1], 16),
				peer.sin_port, peerLength);

            sleep(3);
            close(sockfd);
            exit(0);
    }   
 
    while(1)
    {   
        cpid = wait(NULL);
        if(cpid==-1){
            perror("end of wait");
            break;
        }
        printf("pid#%d exit...\n",cpid);
    }
    return 0;
}
