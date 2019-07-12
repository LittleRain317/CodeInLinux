#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using std::vector;
using std::istringstream;
using std::istream;
using std::string;
using std::cin;
using std::cout;
using std::endl;
istream & function(istream & is)
{
	vector<string> num;
	string n;
	while (is >> n)
		num.push_back(n);
	cout << is.fail() << endl;
	is.clear();
	for (const auto & it : num)
		cout << it << endl;
	return is;
}

int main()
{
	string temp;
	getline(cin, temp);
	istringstream is(temp);
	function(is);
	cout << is.fail() << endl;
	return 0;
}
