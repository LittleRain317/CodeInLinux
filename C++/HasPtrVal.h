#ifndef __HASPTRVALUE_H_
#define __HASPTRVALUE_H_

#include <string>
#include <algorithm>
#include <iostream>


class HasPtr
{
	friend void swap(HasPtr& h1, HasPtr& h2);
	private:
		std::string * str = new std::string();
		int i = 0;
	public:
		HasPtr() = default;
		HasPtr(const std::string &s) : str(new std::string(s)), i(0) { std::cout << "string" << std::endl; }
		HasPtr(const char *  s) : str(new std::string(s)), i(0) { std::cout << "char *" << std::endl; }
		HasPtr(const HasPtr& has) : str(new std::string(*(has.str))), i(has.i) { }
		HasPtr& operator= (HasPtr has);
		~HasPtr() { delete str; }
		bool operator<(const HasPtr& has)
		{
			return *str < *has.str;
			std::cout << "调用<" << std::endl;
		}
};

inline void swap(HasPtr& h1, HasPtr& h2)
{
	using std::swap;
	swap(h1.str, h2.str);
	swap(h1.i, h2.i);
	std::cout << "调用swap函数" << std::endl;
}
#endif
