#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
int main(void)
{
	string s1;
	while (getline(cin, s1))
		if (!s1.empty())
			cout << s1 << endl;
		else
			cout << "空行" << endl;
	return 0;
}
