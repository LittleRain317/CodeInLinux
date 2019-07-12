#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	int grade = 0;
	cin >> grade;
	string finalgrade = (grade < 60 )? "fail " : grade <= 75 ? "low pass" : grade <= 85 ? "pass" : "high pass";
	cout << finalgrade << endl;
	return 0;
}
