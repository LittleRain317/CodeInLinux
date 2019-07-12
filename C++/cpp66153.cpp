#include <iostream>
using namespace std;
int cal(int &, int &)
{
	cout << "非常量" << endl;
	return 0;
}
int cal(const int &, const int &)
{
	cout << "常量" << endl;
	return 0;
}
int calc(char *, char *)
{
	cout << "非常量char" << endl;
}
int calc(const char *, const char *)
{
	cout << "常量char" << endl;
}
int calc(char *const, char *const)
{
	cout << "顶层char" << endl;
}
int main()
{
	cal(1, 2);
	int i = 10;
	const int b = 20;
	cal(i, b);
	calc("fewr", "fewr");
	 char * p = "hek";
	char ch = 'a';
	char *p2 = &ch;
	calc(p, p2);
	calc("faweg", "wrq");
	return 0;
}
