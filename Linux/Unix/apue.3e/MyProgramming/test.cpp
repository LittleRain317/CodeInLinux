#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string> 
using namespace std;

#define IPSTR "139.196.84.233" //服务器IP地址;
#define PORT 80
#define BUFSIZE 1024
 int sockfd, ret, i, h;
        struct sockaddr_in servaddr;
        char str1[4096], str2[4096], buf[BUFSIZE], *str;
        socklen_t len;
        fd_set   t_set1;
        struct timeval  tv;

int init()
{
		         
         //创建套接字
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
                printf("创建网络连接失败,本线程即将终止---socket error!\n");
                exit(0);
        };
 
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(PORT);
        if (inet_pton(AF_INET, IPSTR, &servaddr.sin_addr) <= 0 ){
                printf("创建网络连接失败,本线程即将终止--inet_pton error!\n");
                exit(0);
        };

		return 0;
}
int main(int argc, char **argv)
{
	init();
         
        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
                printf("连接到服务器失败,connect error!\n");
                exit(0);
        }
		/*
GET /meet/ HTTP/1.1\r\n
Host: 59.55.130.208:16666\r\n
Connection: keep-alive\r\n
Cache-Control: max-age=0\r\n
Upgrade-Insecure-Requests: 1\r\n
User-Agent: 24ksb
Accept: text/html\r\n
Accept-Encoding: gzip, deflate\r\n
Accept-Language: zh-CN,zh;q=0.9\r\n
\r\n\r\n
		 */
        printf("与远端建立了连接\n");
        memset(str2, 0, 4096);
        strcat(str2, "theDataToPost");
        str=(char *)malloc(128);
        len = strlen(str2);
        sprintf(str, "%d", len);
 
        memset(str1, 0, 4096);
        string temp; 
		temp = 
			  "GET / HTTP/1.1\r\n"
              "Host: abc.akmduj.cn\r\n"
              "Connection: keep-alive\r\n"
              "Cache-Control: max-age=0\r\n"
              "Upgrade-Insecure-Requests: 1\r\n"
              "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.86 Safari/537.36\r\n"
              "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange  ;v=b3\r\n"
              "Accept-Encoding: gzip, deflate\r\n"
              "Accept-Language: zh-CN,zh;q=0.9\r\n"
              "\r\n";

        ret = write(sockfd,temp.c_str(),temp.length());
        if (ret < 0) {
                printf("发送失败！错误代码是%d，错误信息是'%s'\n",errno, strerror(errno));
                exit(0);
        }else{
                printf("消息发送成功，共发送了%d个字节！\n\n", ret);
        }
 
        FD_ZERO(&t_set1);
        FD_SET(sockfd, &t_set1);
 
        while(1){
			sleep(2);
                tv.tv_sec= 0;
                tv.tv_usec= 0;
                h= 0;
                printf("--------------->1");
                h= select(sockfd +1, &t_set1, NULL, NULL, &tv);
                printf("--------------->2");
 
                //if (h == 0) continue;
                if (h < 0) {
                        close(sockfd);
                        printf("在读取数据报文时SELECT检测到异常，该异常导致线程终止！\n");
                        return -1;
                };
 
                if (h > 0){
                        memset(buf, 0, 4096);
                        i= read(sockfd, buf, 4095);
                        if (i==0){
                                close(sockfd);
                                printf("读取数据报文时发现远端关闭，该线程终止！\n");
                                return -1;
                        }
 
                        printf("%s\n", buf);
                }
        }
        close(sockfd);
		printf("结束\n");
 
}
