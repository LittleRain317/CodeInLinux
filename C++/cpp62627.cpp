#include <iostream>
#include <initializer_list>
#include <vector>
using std::vector;
using std::initializer_list;
using std::cin;
using std::cout;
using std::endl;
int function(initializer_list<int> number)
{
	int sum = 0;
	for (const auto it : number)
		sum += it;
	return sum;
}
int main()
{
	vector<int> vec;
	int number = 0;
	while (cin >> number)
		vec.push_back(number);
	cout << "和为:" << function({vec[0], vec[1], vec[2]}) << endl;
	return 0;
}
