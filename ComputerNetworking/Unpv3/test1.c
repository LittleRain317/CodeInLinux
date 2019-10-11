#include <unp/unp.h>

#define DEST_IP "127.0.0.1" 
int main(int argc, char ** argv)
{ 
int sockfd, n; 
char buf[100]; 
char serv_ip[20], guest_ip[20]; 
struct sockaddr_in servaddr; 

sockfd = Socket(AF_INET, SOCK_STREAM, 0); 

bzero(&servaddr, sizeof(struct sockaddr_in)); 
servaddr.sin_family = AF_INET; 
servaddr.sin_port = htons(10010); 
Inet_pton(AF_INET, DEST_IP, &servaddr.sin_addr); 

Connect(sockfd, (SA *)&servaddr, sizeof(servaddr)); 

struct sockaddr_in serv, guest; 
socklen_t serv_len = sizeof(serv); 
socklen_t guest_len = sizeof(guest); 
getsockname(sockfd, (SA *)&guest, &guest_len); 
getpeername(sockfd, (SA *)&serv, &serv_len); 

Inet_ntop(AF_INET, &guest.sin_addr, guest_ip, sizeof(guest_ip)); 
Inet_ntop(AF_INET, &serv.sin_addr, serv_ip, sizeof(serv_ip)); 
printf("host %s:%d, guest %s:%dn", serv_ip, ntohs(serv.sin_port), guest_ip, ntohs(guest.sin_port)); 

n = Read(sockfd, buf, 100); 
buf[n] = '?'; 
printf("%sn", buf); 
Close(sockfd); 
exit(0); 
}
