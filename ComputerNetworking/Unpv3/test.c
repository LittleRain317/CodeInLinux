#include <unp/unp.h>
int main(int argc, char ** argv)
{ 
int listenfd,connfd; 
struct sockaddr_in servaddr; 
pid_t pid; char temp[20]; 
listenfd = Socket(AF_INET, SOCK_STREAM, 0); 

bzero(&servaddr, sizeof(servaddr)); 
servaddr.sin_family = AF_INET; 
servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
servaddr.sin_port = htons(10010); 

Bind(listenfd, (SA *)&servaddr, sizeof(servaddr)); 

Listen(listenfd, LISTENQ); 

for( ; ; ) 
{ 
struct sockaddr_in local; 
connfd = Accept(listenfd, (SA *)NULL, NULL); 
if((pid = fork()) == 0) 
{ 
Close(listenfd);
struct sockaddr_in serv, guest; 
char serv_ip[20]; 
char guest_ip[20]; 
socklen_t serv_len = sizeof(serv); 
socklen_t guest_len = sizeof(guest); 
getsockname(connfd, (struct sockaddr *)&serv, &serv_len); 
getpeername(connfd, (struct sockaddr *)&guest, &guest_len); 
Inet_ntop(AF_INET, &serv.sin_addr, serv_ip, sizeof(serv_ip)); 
Inet_ntop(AF_INET, &guest.sin_addr, guest_ip, sizeof(guest_ip)); 
printf("host %s:%d guest %s:%dn", serv_ip, ntohs(serv.sin_port), guest_ip, ntohs(guest.sin_port)); 
char buf[] = "hello world"; 
Write(connfd, buf, strlen(buf)); 
Close(connfd); exit(0);
} 
Close(connfd); 
} 
}
