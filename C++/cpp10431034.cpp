#include <iostream>
#include <iterator>
#include <vector>
using std::vector;
using std::reverse_iterator;
using std::cout;
using std::endl;
int main()
{
	vector<int> vec =  {1, 2, 3, 4, 5, 6, 7};
	auto r = vec.end() - 1;
	for (; r != vec.begin() - 1; --r)
		cout << *r << endl;
	return 0;
}
