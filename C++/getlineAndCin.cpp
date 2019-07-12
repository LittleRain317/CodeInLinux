#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	string s1;
	cin >> s1;
	cout << s1 << endl;
	cin.get();
	string s2;
	getline(cin, s2);
	cout << s2 << endl;
	return 0;
}

