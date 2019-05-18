#include <iostream>
int main(void)
{
	double d = 3.14;
	const int & ir = d;
	std::cout << ir;
	return 0;
}
