#include <iostream>
using namespace std;
void function(int a)
{
	int c = 32;
	auto f = [a] (int b) { return a + b; };
	cout << f(c)<< endl;
}
int main()
{
	function(4);
	return 0;
}
