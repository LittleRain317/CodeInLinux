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
	string repla;
	getline(cin, repla);
	cout << "要替换的字符串:\n" << repla;

	cout << "结果:\n" << regex_replace(str, rege, repla);
	return 0;
}
