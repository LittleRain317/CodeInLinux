#include <iostream>
using namespace std;
void f()
{
	cout << "空!" << endl;
}
void f(int)
{
	cout << "一个int" << endl;
}
void f(int, int)
{
	cout << "两个int" << endl;
}
void f(double, double = 3.14)
{
	cout << "double" << endl;
}
int main()
{
//	f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}
