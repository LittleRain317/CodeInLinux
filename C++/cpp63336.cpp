#include <iostream>
#include <string>
using namespace std;
string (&function(string (&arr)[10]))[10]
{
	for (size_t i = 0; i != 10; ++i)
		arr[i] = "Hello";
	return arr;
}

using arrType = string [10];
arrType & function1(arrType & arr);

auto function2(string  (&arr)[10]) -> string (&) [10];

decltype(arr) function3(string (&arr)[10]);

int main()
{
	string arr[10];
	string (*p)[10] = &function(arr);
	for (size_t i = 0; i != 10; ++i)
		cout << (*p)[i] << endl;
	return 0;
}
