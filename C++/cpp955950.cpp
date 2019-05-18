#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> vec;
	string temp;
	while (cin >> temp)
		vec.push_back(temp);
	int sum = 0;
	for (const auto & it : vec)
		sum += stoi(it);
	cout << sum << endl;
	return 0;
}
