#include <iostream>
using namespace std;
int main(void)
{
	int a = 3, b = 4;
	decltype(a) c = a;//int
	decltype(a = b) d = a;//int &
	cout << a << " " << b << " " << c << " " << d << endl;
	return 0;
}
