#include <iostream>
#include <string>
#include <deque>
using std::string;
using std::deque;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	deque<string> de;
	cout << de.size() << endl;
	string temp;
	cout << temp << endl;
	while (cin >> temp)
		de.push_back(temp);
	cin.clear();
	while (cin >> temp)
		de.emplace_front(temp);
	for (const auto & it : de)
		cout << it << endl;
	return 0;
}
