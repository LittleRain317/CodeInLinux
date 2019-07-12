#include <iostream>
int main(void)
{
	int a[10] = {0};
	int *p1 = a;
        int *p2 = a ;
	p1 += p2 - p1;
	return 0;
}
