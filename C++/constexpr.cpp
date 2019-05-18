#include <iostream>
int function(int num);
int main(void)
{
	constexpr int fc = function(3);
	std::cout << fc << std::endl;
	return 0;
}
int function(int num)
{
	return num;
}
