#include <iostream>
using namespace std;
istream & function(istream & is)
{
	int num = 0;
	while (is >> num)
	       cout << num << endl;
	cout << is.fail() << endl;
	is.clear();	
	return is;
}

int main()
{
	function(cin);
	cout << cin.fail() << endl;
	return 0;
}
