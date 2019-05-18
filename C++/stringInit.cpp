#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main(void)
{
	string s1;//空字符串
	string s2(s1);//构造副本
	string s2 = s1;//等价上一个 执行的是拷贝构造函数
	string s3("value");
	string s3 = "value";//等价上一个
	string s4(n, 'c');//n个c
	return 0;
}
