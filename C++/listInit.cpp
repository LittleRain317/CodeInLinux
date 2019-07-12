#include <iostream>
using namespace std;
int main(void)
{
	long double ld = 3.1415926535;
	int a(ld), b = ld;
	int c{ld}, d = {ld};
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
	return 0;
}
