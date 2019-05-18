#include <string>
using std::string;
int main(void)
{
	int i;
	double d;
	const string * ps;
	char * pc;
	void * pv;
	pv = (void *)ps;
	//
	pv = reinterpret_cast<void *>(const_cast<string *>(ps));
	i = int(*pc);
	i = static_cast<int>(*pc);
	pv = &d;
	pc = (char*)pv;
	pc = reinterpret_cast<char *>(pv);
	return 0;
}
