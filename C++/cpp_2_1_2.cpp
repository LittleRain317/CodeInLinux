#include <iostream>
using namespace std;
int main(void)
{
	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl;//32
	cout << u - u2 << endl << "-32无符号:" << (unsigned)-32;//-32转为无符号型的结果
	cout << "Hello"<< endl;
	int i = 10, i2 = 42;
	cout << i2 - i << endl; // 32
	cout << i - i2 << endl; // -32
	cout << i - u << endl; // 0
	cout << u - i << endl;
	return 0;
}
