#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
int main(void)
{
	vector<int> numList(10);
	for (auto it = numList.begin(); it != numList.end(); ++it)
	{
		cin >> (*it);
		(*it) *= 2;
	}
	for (const auto it : numList)
		cout << it << endl;
	vector<int>::difference_type distence = numList.end() -  numList.begin();
	cout << distence << endl;
	return 0;
}
