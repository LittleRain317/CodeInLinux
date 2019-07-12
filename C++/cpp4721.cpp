#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	vector<int> vec;
	int number = 0;
	while (cin >> number)
		vec.push_back(number);
	for (auto it : vec)
		cout << it << endl;
	for (auto & it : vec)
	{
		it = (it % 2 == 0 ? it : 2 * it);
	}
	cout << "翻倍后:" << endl;
	for (auto it : vec)
	{
		cout << it << endl;
	}
}
