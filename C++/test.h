#ifndef TEST_H_
#define TEST_H_
#include <iostream>
using namespace std;
class A
{
	private:
		int a = 0;
	public:
		A(int b) : a(b) { cout << b << endl; } 
		A() : A(5) { cout << " " << endl; }
		A(double b) : A() { cout << "double" << endl;}
};


#endif
