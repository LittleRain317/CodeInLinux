#include <iostream>
#include <cctype>
using namespace std;
int main(void)
{
	string test;
	getline(cin, test);
	for (string::size_type it = (string::size_type)0; it < test.size(); ++it)
	{
//		cout << test[it] << endl;
		if (isalnum(test[it]))
		{
			i;	
		}
	}
	return 0;
}
