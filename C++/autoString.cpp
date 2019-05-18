#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	getline(cin, s);
	for (auto & c : s)
		c = 'x';
	cout << s << endl;
	return 0;
}
