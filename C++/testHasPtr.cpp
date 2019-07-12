#include "HasPtr.h"

HasPtr& HasPtr::operator= (const HasPtr & has)
{
	//递增右侧引用计数器
	//++*has.use;
	++(*(has.use));
	//递减自身的引用计数器
	if (--(*(this->use)) == 0)
	{
		delete use;
		delete ps;
	}
	//开始拷贝
	ps = has.ps;
	i = has.i;
	use = has.use;
	return *this;
}

HasPtr::~HasPtr()
{
	if (--(*(this->use)) == 0)
	{
		delete ps;
		delete use;
		std::cout << "析构" << std::endl;
	}
}
