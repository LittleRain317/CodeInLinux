#include <iostream>
#include <iterator>
using namespace std;
int main(void)
{
	constexpr unsigned row = 50, column = 50;
	int ia[row][column] = {0};
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			ia[i][j] = i * j - 1;
	using ptrArray = int (*)[column];
	for (ptrArray p = ia; p != ia + row; ++p)
	{
		for (int * q = *p; q != *p + column; ++q)
			cout << *q << endl;
	}
	return 0;
}
