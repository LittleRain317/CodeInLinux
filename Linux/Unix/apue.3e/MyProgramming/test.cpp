     #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include <string>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
 
using namespace std;
 
#define ERROR    -1
#define OK          0
#define PORT      80
 
void GetUrlAndPath(const string url, string &HostUrl, string &PagePath)
{
    HostUrl = url;
    PagePath = "/";
    //去除 http:// 字符串
    int pos = HostUrl.find("http://");
    if(pos != -1)
    {
        HostUrl = HostUrl.replace(pos, 7, "");
    }
 
    //去除 https:// 字符串
    pos = HostUrl.find("https://");
    if(pos != -1)
    {
        HostUrl = HostUrl.replace(pos, 8, "");
    }
 
    //提取主机端口和路径
    pos = HostUrl.find("/");
    if(pos != -1)
    {
        PagePath = HostUrl.substr(pos);
        HostUrl = HostUrl.substr(0, pos);
    }
}
 
string getpagecontent(const string url)
{
    //记录主机的信息，包括主机名、别名、地址类型、地址长度和地址列表
    struct hostent *host;
    string HostUrl, PagePath;
 
    //从url获取主机url和路径
    GetUrlAndPath(url, HostUrl, PagePath);
 
    //通过主机名连接主机
    host = gethostbyname(HostUrl.c_str());
    if(host == 0)
    {
        cout<<"gethostbyname error";
        exit(1);
    }
 
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = ((struct in_addr*) (host->h_addr))->s_addr;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1)
    {
        cout<<"create sfd error"<<endl;
        exit(1);
    }
 
    string requestHeader;
    requestHeader   = "GET " + PagePath + " HTTP/1.1\r\n";
    requestHeader += "Host: " + HostUrl + "\r\n";
    requestHeader += "Accept: */*\r\n";
    requestHeader += "User-Agent: Mozilla/4.0(compatible)\r\n";
    requestHeader += "connection:Keep-Alive\r\n";
    requestHeader += "\r\n";
	requestHeader = "GET /timg?image HTTP/1.0\r\nHost: " + HostUrl + "\r\n\r\n";
 
    int ret = connect(sfd, (const sockaddr*)&addr, sizeof(addr));
    if(ret == -1)
    {
        cout<<"connect error"<<endl;
        exit(1);
    }
 
    ret = send(sfd, requestHeader.c_str(), requestHeader.size(), 0);
    if(ret == -1)
    {
        cout<<"send error"<<endl;
        exit(1);
    }
 
    struct timeval timeout = {1, 0};
    setsockopt(sfd, SOL_SOCKET, SO_RCVTIMEO, (char*) &timeout, sizeof(struct timeval));
    char c;
    bool flag = true;
    while(recv(sfd, &c, 1, 0))
    {
        if(c == '\r')
        {
            continue;
        }
        else if(c == '\n')
        {
            if(flag == false)
                break;
            flag = false;
        }
        else
        {
            flag = true;
        }
    }
 
    int len, BUFFERSIZE = 512;
    char buffer[BUFFERSIZE];
    string pagecontent = "";
    while((len = recv(sfd, buffer, BUFFERSIZE-1, 0)) > 0)
    {
        buffer[len] = '\0';
        pagecontent += buffer;
    }
 
    return pagecontent;
}
 
int main()
{
	string temp =    getpagecontent("https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1567636979993&di=7375e5b8bd14bfcb6bec878b24fe220f&imgtype=0&src=http%3A%2F%2Fimg.mp.sohu.com%2Fupload%2F20170525%2Ff3ef19abc3014e9097ddbaa6ea9212ec_th.png");
	int fp = creat("meinv.jpeg", S_IRWXU);
	size_t size= 0;
	size_t n = 0;
	char buff[4096] = { 0 };
	while (size != temp.size()) //一直写直到写完
    {
		n = (temp.size() - size > 4096 ? 4096 : temp.size() - size);
		if (write(fp, buff, n) != n)
		{
			printf("error for write\n");
		}
		size += n;
	}
	close(fp);
    return 0;
}
