#include <iostream>
using namespace std;
auto function(int ) -> int (*)[10]
//int (*function(int i)) [10];
{
	using arrType = int[10];
	arrType *  p = new arrType[1];
	for (int i = 0; i < 10; ++i)
		(*p)[i] = i;
	return p;
}
int main()
{
	int (*p) [10] = function(1);
	for (int i = 0; i < 10; ++i)
		cout << (*p)[i] << endl;
	return 0;
}
