#include <iostream>
#include <string>
using namespace std;
void function(string s, string oldVal, string newVal)
{
	/*if (oldVal.empty())
	{
		s += newVal;
		cout << s << endl;
		return;
	}
	auto index = s.find(oldVal);
	cout << index << endl;
	s.erase(index, oldVal.size());
	s.insert(index, newVal);
	cout << s << endl;*/
	if (oldVal.empty())
	{
		s += newVal;
		cout << s << endl;
		return;
	}
	s.replace(s.find(oldVal), oldVal.size(), newVal);
	cout << s << endl;
	return;
}
int main()
{
	function("thru", "u", "ough");
	return 0;
}
