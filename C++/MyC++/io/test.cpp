#include <iostream>
#include "io.h"
using std::cout;
using std::endl;
int main()
{
	Io io;
	io.setBit(8);
	io.setBit(4);
	io.setBit(1);
	cout << io.eof() << endl;
	cout << io.fail() << endl;
	cout << io.bad() << endl;
	cout << io.good() << endl;
	
	cout << "清空" << endl;
	for (int i = 0; i != 8; ++i)
	{
		io.setBit(i + 1);
		std::cout << io.getBit(i + 1) << std::endl;
	}
	io.clear(static_cast<Io::iostate>(248));
	cout << io.getBit(1) << endl;
	cout << io.getBit(2) << endl;
	cout << io.getBit(3) << endl;
	std::cout << static_cast<int>(io.rdstate()) << std::endl;
	return 0;
}
