#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main()
{
	vector<int> vec;
	int number = 0;
	while (cin >> number)
		vec.push_back(number);
	vector<int> copy;
	copy.assign(vec.cbegin(), vec.cend());
	for (const auto &  it : copy)
		cout << it << endl;
	return 0;
}
