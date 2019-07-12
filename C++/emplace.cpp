#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main()
{
	vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vector<int> copy(vec);
	vec.erase(vec.begin() + 2);
	for (auto it : vec)
		cout << it << endl;
	return 0;
}
