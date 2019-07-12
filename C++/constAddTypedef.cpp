#include <iostream>
using std::endl;
using std::cout;
typedef char * ptrChar;
typedef double * ptrDouble;
int main(void)
{
	char ch = 'a';
	double pi = 3.14;
	const ptrChar p1 = &ch;
	ptrDouble const p2 = &pi;

	//指针内容修改
	*p1 = 'b';
	*p2 = 1.0;
	cout << ch << " " << pi << endl;
	//指针指向修改
	++p1;
	++p2;
	return 0;
}
