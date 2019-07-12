#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	vector<int> numList;
	int number = 0;
	while (cin >> number)
		numList.push_back(number);
	auto begin = numList.begin();
	auto end = numList.end() - 1;
	for (auto it = begin; it != numList.end(); ++it, --end)
	{
		cout << *it + *end << endl;
	}
	return 0;
}
