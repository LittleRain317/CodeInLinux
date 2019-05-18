#include <iostream>
using namespace std;
int main(void)
{
	const int a = 10;
	const int * p = &a;
	decltype(*p) d = 20;//d的类型为const int &
	//否则无法用字面值进行d的初始化
	//	decltype(a) c;//c的类型为const int
	decltype((a)) c = 42;//此时c的类型应该为const int &;	
//	c = 32;//推测成立，此行代码将会报错
	return 0;
}
