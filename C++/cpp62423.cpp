#include <iostream>
#include <iterator>
using std::begin;
using std::end;
using std::cout;
using std::endl;
void print(const int i)
{
	cout << i << endl;
}
void print(const int * j)
{
	cout << *j << endl;
}
void print(const int * begin, const int * end)
{
	while (begin != end)
	{
		cout << *begin++ << endl;
	}
}
int main(void)
{
	int i = 0;
	int j[2] = {0, 1};
	print(i);
	print(j);
	print(begin(j), end(j));
	return 0;
}
