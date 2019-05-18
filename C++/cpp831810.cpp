#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::cerr;
int main()
{
	ifstream ifile("test.txt");
	vector<string> word;
	if (!ifile)
	{
		cerr << "文件打开失败!";
		return 1;
	}
	string temp;
	while (getline(ifile, temp))
		word.push_back(temp);
	string read;
	for (const auto & it : word)
	{
		istringstream is(it);
		while (is >> read)
			cout << read << endl;
	}
	return 0;
}
