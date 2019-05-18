#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <vector>
using std::vector;
using std::list;
using std::find;
using std::reverse_iterator;
using std::cout;
using std::endl;
int main()
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> li(vec.rbegin() + 2, vec.rbegin() + 7);
	for (auto it : li)
		cout << it << endl;
	return 0;
}
