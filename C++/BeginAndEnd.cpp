#include <iostream>
#include <iterator>
using std::cout;
using std::endl;
using std::end;
using std::begin;
int main(void)
{
	constexpr unsigned size = 10;
	int arr[size] = {0};
	for (auto it = begin(arr); it != end(arr); ++it)
		*it = 100;	
	for (auto it : arr)
		cout << it <<endl;
	return 0;
}

