#include <iostream>
#include <string>
using namespace std;
class test
{
	public:
		test(string temp) { cout << "构造函数" << endl; }
		~test() { cout << "析构函数" << endl; }
};
/*
test & function(test t)
{
	cout << "普通" << endl;
	return t;
}*/


test& function(test & t)
{
	cout << "引用" << endl;
	return t;
}

/*
const test& function(const test & t)
{
	cout << "常量" << endl;
	return t;
}*/

int main()
{
	string he("hello");
	function(he);
	return 0;
}
