#include <iostream>
using namespace std;
int main(void)
{
	int i = 0, &r = i;
	auto a = r;
	//auto一般会默认忽略掉顶层const
	const int ci = i, &cr = ci;
	auto &n = i, *p2 = &ci;
	//	auto k = ci, &l = i;
//	k = 1, l = 2;	
	//	const auto &h = 42;
//	auto b = ci;
//	b = 10;
//	auto c = cr;
//	c = 10;
//	auto d = &i;
//	auto e = &ci;
//	(*d)++;
//	(*e)++;
//	const auto p = &i;
//	(*p)++;
//	p++;
	cout << "i = " << i << " " << "r = " << r << endl;
	cout << "ci = " << ci << " " << "cr = " << cr << endl;
	//auto iN = 1, dN = 3.14;
	return 0;
}
