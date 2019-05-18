#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	string text;
	vector<string> stringList;
	while (getline(cin, text))
		stringList.push_back(text);
	for (vector<string>::iterator it = stringList.begin() ; it != stringList.end() &&  !it->empty(); ++it)
		for (auto & it : *it)
			it = toupper(it);
	for (const auto it : stringList)
		cout << it << endl;
	return 0;
}
