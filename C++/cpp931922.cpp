#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec;
	int temp = 0;
	while (cin >> temp)
		vec.push_back(temp);
	cout << cout.fail() << endl;
	cout << vec.capacity() << endl;
	auto iter = vec.begin(), mid = vec.begin() + vec.size() / 2;
	while (iter != mid)
		if (*iter == 3)
			vec.insert(iter, 2 * 3);
		else
			++iter;
	for (auto it : vec)
		cout << it << endl;
	return 0;
}
