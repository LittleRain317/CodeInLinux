#include <iostream>
#include <string>
#include <initializer_list>
#include <system_error>
using namespace std;
enum errorcodeenum
{
	err1,
	err2,
	err3,
}err;
void error_msg(error_code e, initializer_list<string> il)
{
	cout << e.message() << endl;
	for (auto & it : il)
	{
		cout << it << endl;
	}
}
int main()
{
	error_msg(error_code(errorcodeenum(1)), {"hello", "world"});
	
	return 0;
}
