#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s(100, 0);
	char ch = 0;
	while (cin >> ch)
		s += ch;
	cout << s << endl;
	return 0;
}
