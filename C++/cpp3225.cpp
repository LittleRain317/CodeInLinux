#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::endl;
using std::cout;
int main(void)
{
	string maxString;
	string temp;
	while (getline(cin, temp))
	{
		maxString += " " + temp;
	}
	cout << maxString << endl;
	return 0;
}
