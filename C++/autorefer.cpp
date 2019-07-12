#include <iostream>
int main(void)
{
	int a = 10;
	int &b = a;
	auto c = b;
	std::cout << c;
	return 0;
}
