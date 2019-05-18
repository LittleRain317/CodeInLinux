#include <iostream>
#include <forward_list>
using std::forward_list;
using std::cout;
using std::endl;
int main()
{
	forward_list<int> list{3, 5, 61, 64, 73, 23};
	auto it = list.before_begin();
	auto next = list.begin();
	while (next != list.end())
	{
		if (*(next) % 2 == 1)
			next = list.erase_after(it);
		else
		{
			++next;
			++it;
		}
	}
	for (const auto & it : list)
		cout << it << endl;
	return 0;
}

