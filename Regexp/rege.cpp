#include <string>
#include <iostream>
#include <regex>
#include <fstream>
using namespace std;
void read(string & str)
{
	ifstream ifile("temp.txt");
	while (!ifile.eof())
	{
		string temp;
		getline(ifile, temp);
		temp += "\n";
		str += temp;
	}
	str.pop_back();
	ifile.close();
}
int main()
{
	string str;
	read(str);
	string regexp;
	getline(cin, regexp);
	regex rege;
	rege = regexp;
	cout << "要匹配的字符串:\n" << str;
	cout << "正则表达式:\n" << regexp;

	smatch result;
	regex_search(str, result, rege);
	cout << "整个结果:" << result[0] << "\t长度:" << result.length(0) << endl;
	for (size_t i = 1; i < result.size(); ++i)
	{
		cout << "子字符串" << i << ":" << result[i] << "\t长度:" << result.length(i) << endl;
	}
	return 0;
}
