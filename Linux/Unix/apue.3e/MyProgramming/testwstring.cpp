#include <string>
#include <iostream>
#include <locale>
using namespace std;
int main()
{
	locale::global(locale("en_US.UTF-8"));
	wstring temp = L"24k傻逼";
	for (auto && it : temp)
	{
		wcout << it << endl;
	}
	return 0;
}
