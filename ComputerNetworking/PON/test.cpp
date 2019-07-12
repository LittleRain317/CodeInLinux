#include "transceiver.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	Transceiver p("1.2.3.4");
	Transceiver p2("4.5.6.7");
	p.Transfer(p2);
	p.Transfer(p2);
	p2.Transfer(p);
	p2.Transfer(p);
	p.Transfer(p2);
	p.Transfer(p2);
	return 0;
}
