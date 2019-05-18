#include <iostream>
#include <regex>
#include <cstdlib>
#include <string>
#include <cctype>
using std::stoi;
using std::regex;
using std::regex_match;
using std::cerr;
using std::endl;
using std::string;
using std::cout;
int main(int argc, const char * argv[])
{
	string command("box");
	if (argc == 1)
	{
		system(command.c_str());
		return 0;
	}
	else 
	{
		string seconde = argv[1];
		regex r("^(-[1-9][0-9]*)$");
		if (regex_match(seconde, r))
		{
			for (int current = 2; current < argc; ++current)
			{
				command += ' ';
				command += argv[current];
			}	
			int num = stoi(seconde);
			num *= -1;
			for (int current = 1; current != num; ++current)
			{
				command += " | box";
			}
		}
		else	
		{	
			for (int current = 1; current < argc; ++current)
			{
				command += ' ';
				command += argv[current];
			}
		}
	}
	system(command.c_str());
	return 0;
}
