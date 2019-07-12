#include <string>
#include <iostream>
#include <cstring>
using std::string;
using std::cout;
using std::endl;
int main(void)
{
	const char a[] = "abced";
	const char b[] = "ABCDE";
	char c[strlen(a) + strlen(b) + 1] = {0};
	strcpy(c, a);
	strcat(c, b);
	cout << c <<endl;
	return 0;
}
