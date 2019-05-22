#include "student.h"
#include "teacher.h"

int main()
{
	Teacher* t = new Teacher();
	Student* s[2] = {new Student(), new Student()};
	t->addObserver(s[0]);
	t->addObserver(s[1]);
	t->notifyObserver();
	delete s[0];
	delete s[1];
	delete t;
	return 0;
}
