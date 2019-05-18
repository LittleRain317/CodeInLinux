#include <list>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	list<int> li;
	vector<int> copy;
	int temp = 0;
	while (cin >> temp)
	       copy.push_back(*(li.insert(li.cbegin(), temp)));
	for (const auto & it : copy)
		cout << it << endl;	
	return 0;
}
