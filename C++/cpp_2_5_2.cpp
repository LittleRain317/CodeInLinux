#include <iostream>
using std::cout;
using std::endl;
int main(void)
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto &g = ci;
	cout << a << endl;
	a = 42;
	cout << "赋值后:" << a << endl;
	cout << b << endl;
	b = 42;
	cout << "赋值后:" << b << endl;
	cout << c << endl;
	c = 42;
	cout << "赋值后:" << c << endl;
	cout << d << endl;
	d = (int *)42;
	cout << "赋值后:" << d << endl;
	cout << e << endl;
	e = (const int *)42;
	cout << "赋值后:" << e << endl;
	cout << g << endl;
//	g = 42;//g为const in &
	cout << "赋值后:" << g << endl;
	return 0;
}
