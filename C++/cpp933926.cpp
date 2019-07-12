#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main()
{
	int ia[] = { 2, 4, 24, 51, 53, 654, 654, 73};
	list<int> list;
	list.assign(begin(ia), end(ia));
	vector<int> vec;
	vec.assign(begin(ia), end(ia));
	auto it = vec.begin();
	auto & next = *(it + 1);
	while (it != vec.end())
		if (*it % 2 == 0)
		{	it = vec.erase(it);
			cout << next << endl;
		}else
			++it;
	for (auto & it : list)
		cout << it << endl;
	return 0;
}
