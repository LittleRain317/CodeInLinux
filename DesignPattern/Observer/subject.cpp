#include "subject.h"

void Subject::addObserver(Observer* observer)
{
	observerList.push_back(observer);
}

void Subject::removeObserver()
{
	if (!observerList.empty())
		observerList.pop_back();
}
