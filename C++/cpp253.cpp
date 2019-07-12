#include <iostream>
using namespace std;
int main(void)
{
	int a = 3, b = 4;
	decltype(a) c = a;//int 
	decltype((b)) d = a;//int &
	++c;//4
	++d;//4
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
	return 0;
}
