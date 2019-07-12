/*
 *  引用本身不是对象
 *  不能定义引用的引用
 *
 */
#include <iostream>
int main(void)
{
	int a = 10;
	int & b = a;
	int && c = b;
	return 0;
}
