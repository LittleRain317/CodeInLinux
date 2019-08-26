#include <setjmp.h>
#include <stdio.h>
int global = 1;
void f1();
int main()
{
	static int stavar = 2;
	int autovar = 3;
	if(setjmp(env_alrm) != 0)
		;
	return 0;
}
