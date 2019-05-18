#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cin;
using std::cout;
int main(void)
{
	string word;
	while (cin >> word)
		cout << word << endl;
	cout << "终止" << endl;
	return 0;
}
