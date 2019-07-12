#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
using std::istringstream;
using std::ostringstream;
using std::string;
using std::ifstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
struct PersonInfo
{
	string name;
	vector<string> phones;
};

string& format(string& nums)
{
	nums += " ";
	return nums;
}	

bool valid(const string & nums)
{
	for (const auto & it : nums)
		if (std::isalpha(it))
			return false;
	return true;
}
int main()
{
	string line, word;
	vector<PersonInfo> people;
	ifstream ifile("test.txt");
	while (getline(ifile, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		record.clear();
		people.push_back(info);
	}
/*	for (const auto & it : people)
**	{	
**		cout << "name:" << it.name << " " << "phones:" ;
**		for (const auto & each : it.phones)
**			cout << each << " ";
**		cout << endl;
**	}
*/
	for (auto & entry: people)
	{
		ostringstream formatted, badNums;
		for (auto & nums : entry.phones)
		{
			if (!valid(nums))
			{
				badNums << " " << nums;
			}
			else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
	}	
	return 0;
}
