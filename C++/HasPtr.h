#ifndef __HASPTR_H_
#define __HASPTR_H_

#include <string>
#include <iostream>
class HasPtr
{
	public:
		HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)){ }
		HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use;}
		HasPtr& operator= (const HasPtr &);
		~HasPtr();
	private:
		std::string *ps;
		int i;
		std::size_t *use;
};

#endif
