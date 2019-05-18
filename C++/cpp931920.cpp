#include <list>
#include <deque>
#include <iostream>
using namespace std;
int main()
{
	deque<int> odd;
	deque<int> even;
	list<int> li;
	int temp = 0;
	while (cin >> temp)
		li.push_back(temp);
	for (const auto & it : li)
		if (it & 1 == 1)
			odd.push_back(it);
		else
			even.push_back(it);
	for (const auto & it : odd)
		cout << it << " ";
	cout << endl;
	cout << "偶数:" << endl;
	for (const auto & it : even)
		cout << it << " ";
	cout << endl;
	return 0;
}
