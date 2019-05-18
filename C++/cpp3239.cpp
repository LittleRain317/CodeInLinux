#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	const string s = "Hello ";
	for (auto & it : s)
	//	it = 'x';
	cout << s << endl;
	return 0;
}
