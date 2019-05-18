#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<char> vec {'a', 'b', 'c'};
	string s(vec.begin(), vec.end());
	cout << s << endl;
	return 0;
}
