#include <QCoreApplication>
#include <iostream>
#include <string>
#include <map>
using std::map;
using std::string;
using std::cin;
using std::cout;
class S
{
private:
    map<int, int> num;
    map<int, char> ch;
    map<int, char> x;
public:
    void scanner(string & str)
    {
        for (int i = 0; i < str.length(); ++i)
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                x[i] = str[i];
            }
        if (str[i] == '+')
        {
            ch[i] = str[i];
        }
        if (str[i] == '-')
        {
            ch[i] = str[i];
        }
        if (str[i] == '*')
        {
            ch[i] = str[i];
        }
        if (str[i] == '=')
        {
            ch[i] = str[i];
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            num[i] = str[i];
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   // a + 2 * 5a = -32 a;
   //jiang weizhishuhebing
    void add_X(string start)
    {
        int x = 0;
        if (start[i] shi *)
        {
           for () jiluzhgeshuzi;
        }
    }

    string str = "NULL";
    cin >> str;
   // char * ch = new char[str.length()];
    return a.exec();
}
/*
作者:littlerain
题目:p1015 计算器的改良
*/

/*
//如何写一份可以提交的代码？以P1000 A+B为例
#include <iostream>
using namespace std;
int main()
{
    int a, b; //定义两个变量名
    cin >> a >> b; //从标准输入流中输入两个整数
    cout << a + b << endl; //输出到标准输出流中

}
// 完成程序以后，点击下方的提交，即可看到测试结果
*/
//先把常数项全部移到右边也就是计算常数项的值 在计算未知数的系数




