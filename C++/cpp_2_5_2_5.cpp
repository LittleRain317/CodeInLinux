#include <iostream>
#include <typeinfo>
using namespace std;
int main(void)
{
	const int i = 42;
	auto j = i;//j的类型为int;
	j = 10;//成立
	const auto &k = i;//k的类型为const int
	k = 10;//成立
	auto *p = &i;//p的类型为const int *
	*p = 23;
	--p;//成立
	const auto j2 = i, &k2 = i;//j2的类型为const int, k2的类型为const int
//cout << decltype(j) << endl;
	j2 = 10;
	k2 = 10;
//	cout << typeid(j).name() << endl;
//	cout << typeid(k).name() << endl;
//	cout << typeid(p).name() << endl;
//	cout << typeid(j2).name() << endl;
//	cout << typeid(k2).name() << endl;
	return 0;
}
