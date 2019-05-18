#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cin;
int main(void)
{
	vector<string> stringList;
	string temp;
	while (cin >> temp)
		stringList.push_back(temp);
	for (vector<string>::size_type it = 0; it < stringList.size(); ++it)
		std::cout << stringList[it] << std::endl;
	return 0;
}
