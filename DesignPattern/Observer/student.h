#ifndef STUDENT_H_
#define STUDENT_H_

#include "observer.h"
#include <iostream>
using std::cout;
using std::endl;

class Student : public Observer
{
	public:
		virtual void update()
		{
			cout << "我收到了消息" << endl;
		}
};
#endif
