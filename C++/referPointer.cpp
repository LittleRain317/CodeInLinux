/*
 * 引用不是对象没有实际地址不能定义指向引用的指针
 */

#include <iostream>
using namespace std;
int main(void)
{
	int a = 10;
	int &b = a;
	int  *p = &b;
	cout << p << " " << &a;
	return 0;
}
