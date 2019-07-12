#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> v;
	int number = 0;
	while (cin >> number)
		v.push_back(number);
	auto cnt = v.size();
	for (vector<int>::size_type ix = 0;
			ix != v.size(); ix++, cnt--)
		v[ix] = cnt;
	for (auto it : v)
		cout << it << " ";
	cout << endl;
	return 0;
}
