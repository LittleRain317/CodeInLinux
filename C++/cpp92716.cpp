#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
	list<int> li{3, 4, 5, 6, 7};
	vector<int> vec{1, 2, , 3, 4, 5};
	auto i = li.cbegin();
	auto v = vec.cbegin();
	while (i != li.cend() && v != vec.cend())
	{
		++i, ++v;
	}
	return 0;
}
