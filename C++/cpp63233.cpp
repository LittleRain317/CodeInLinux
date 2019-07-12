#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
void function(const vector<string> & str, int begin, int end)
{
	if (begin == end)
		return;
	else
	{
		cout << str[begin] << endl;
		function(str, begin + 1, end);
	}
}
int main()
{
	vector<string> vec;
	string temp;
	while (cin >> temp)
		vec.push_back(temp);
	function(vec, 0, vec.size());
	return 0;
}
