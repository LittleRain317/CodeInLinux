#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <vector>

using std::vector;
class Observer;
class Subject
{
	public:
		vector<Observer*> observerList;
		virtual void addObserver(Observer* observer);
		virtual void removeObserver();
		virtual void notifyObserver() = 0;
		virtual ~Subject(){}
};

#endif
