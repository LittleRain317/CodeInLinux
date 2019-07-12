#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	vector<string> stringList;
	string temp;
	while (cin >> temp)
		stringList.push_back(temp);
	for (auto &itVector : stringList)
		for (auto & itString : itVector)
			itString = toupper(itString);
	for (auto it : stringList)
		cout << it << endl;

	return 0;
}
