#include <iostream>
#include <vector>
#include <iterator>
using std::vector;
using std::iterator;
using std::cout;
using std::endl;
int main(void)
{
	int a[10] = {0};
	int b[10] = {0, 1};
	if (sizeof(a) / sizeof(a[0]) == sizeof(b) / sizeof(b[0]))
	{
		for (size_t index = 0; index < sizeof(a) / sizeof(a[0]); ++index)
			if (a[index] == b[index])
				continue;
			else
			{	
				cout << "数组不相等" << endl;
				break;
			}
	}
	else
		cout << "数组不相等" << endl;
	
	vector<int> v1{1, 2};
	vector<int> v2{2, 3};
	if (v1.size() == v2.size())
	{
		auto it1 = v1.cbegin();
		auto it2 = v2.cbegin();
		while (it1 != v1.cend())
		{	
			if (it1 == it2)
			{
				++it1;
				++it2;
			}
			else
			{
				cout << "矢量不相同" << endl;
				break;
			}
		}
	}	
	return 0;
}
