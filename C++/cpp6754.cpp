#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
int f1(int a, int b)
{
	return a + b;
}
int f2(int a, int b)
{
	return a - b;
}
int f3(int a, int b)
{
	return a * b;
}
int f4(int a, int b)
{
	return a / b;
}
int main()
{
	vector<int (*)(int, int)> vec;
	vec.push_back(f1);
	vec.push_back(f2);
	vec.push_back(f3);
	vec.push_back(f4);
	cout << "add:" << vec[0](1, 2) << endl;
	cout << "sub:" << vec[1](2, 3) << endl;
	cout << "mul:" << vec[2](3, 4) << endl;
	cout << "/:" << vec[3](5, 6) << endl;
	return 0;
}

