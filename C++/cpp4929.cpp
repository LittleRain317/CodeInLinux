#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int x[10];
	int *p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	cout << sizeof(int *) << endl;
	return 0;
}
