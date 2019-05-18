#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::find_if;
using std::cin;
using std::bind;
using std::ref;
using std::cout;
using std::vector;
using std::endl;
using namespace std::placeholders;
using std::cin;
using std::string;
bool check_size(const string & str, size_t size)
{
	return str.size() <  size;
}

int function(const string & str, const vector<int> & vec)
{
	return *find_if(vec.cbegin(), vec.cend(), bind(check_size, str, _1)); 
}
int main()
{
	vector<int> vec;
	string temp;
	cin >> temp;
	int num = 0;
	while (cin >> num)
		vec.push_back(num);
	cout << temp << endl;
	cout << function(temp, vec) << endl;
	return 0;
}
