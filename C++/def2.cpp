#include <iostream>
using namespace std;
extern int i;
extern int b = 3;
int main(void)
{
//	extern int b = 3;
	cout << "i= " << i << endl;
	return 0;
}
