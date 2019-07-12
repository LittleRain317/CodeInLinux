#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
	vector<string> sv{10, "h1"};
	vector<string> sv2(10, "h2");
	for (auto it : sv2)
		cout << it << endl;
	cout << "sv" << endl;
	for (auto it : sv)
	{
		cout << it << endl;
	}
	return 0;
}
