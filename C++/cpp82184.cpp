#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;
int main()
{
	ifstream is("test.txt");
	vector<string> vec;
	string temp;
	while (is >> temp)
	       vec.push_back(temp);
	for (const auto & it : vec)
		cout << it << endl;
	return 0;	
}
