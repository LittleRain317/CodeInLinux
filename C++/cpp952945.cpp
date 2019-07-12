#include <iostream>
#include <string>
using namespace std;
string function(string name, string front, string next)
{
	name.insert(0, front);
	name.insert(name.size(), next);
	return name;
}
int main()
{
	cout << function("hello", "---", "world") << endl;
	return 0;
}
