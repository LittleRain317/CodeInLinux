#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool function(const string & str)
{
	return str.size() > 5;
}
int i = 2;
int main()
{	
	vector<int> vec;
	int str;
	while (cin >> str)
		vec.push_back(str);
	for_each(vec.begin() , vec.end(), [] (const int & f) { cout << f << endl; });
	return 0;
}
