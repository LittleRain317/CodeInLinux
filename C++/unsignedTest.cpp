#include <iostream>
using namespace std;
int main(void)
{
	unsigned u = 10;
	unsigned u1 = 42;
	unsigned u2 = 10;
	cout << u1 - u2 << endl;
	cout << u2 - u1 << endl;//结果为unsigned类型
	int i = -42;
	cout << i + i << endl;
	cout << u + i << endl;
	for (unsigned u3 = 10; u3 >= 0; --u3)
		cout << u3 << endl;
	return 0;
}
