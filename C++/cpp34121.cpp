#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cin;
using std::endl;
using std::cout;
int main(void)
{
	vector<int> v1;
	for (auto it = v1.cbegin(); it != v1.cend(); ++it)
		cout <<  *it << endl;

	return 0;
}
