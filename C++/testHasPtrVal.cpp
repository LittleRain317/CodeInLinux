#include "HasPtrVal.h"

HasPtr& HasPtr::operator= (HasPtr ha)
{
	swap(*this, ha);
	return *this;
}

