#ifndef TEACHER_H_
#define TEACHER_H_

#include "subject.h"
#include <iostream>
using std::endl;
using std::cout;

class Teacher: public Subject
{
	public:
		virtual void notifyObserver()
		{
			cout << "开始通知" << endl;
			for (const auto& it : observerList)
				it->update();
		}
};

#endif
