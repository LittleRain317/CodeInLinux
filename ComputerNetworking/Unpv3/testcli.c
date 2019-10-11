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
    inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr);
    servaddr.sin_port = htons(2989);
    
    for(int i=0;i<20;i++)
    {   
        cpid = fork();
        if(cpid == 0)
        {   
            sockfd = socket(AF_INET,SOCK_STREAM,0);
            rc = connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
            if(rc == -1) 
            {   
                perror("connect error");
                exit(0);
            }   
            printf("pid#%d connected...\n",getpid());
            sleep(3);
            close(sockfd);
            exit(0);
        }   
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
