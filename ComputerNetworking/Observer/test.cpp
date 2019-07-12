#include "protocol.h"
#include "user.h"
#include <iostream>
using namespace std;

class TestProtocol : public Protocol
{
	public:
		void transfer(Protocol* protocol)
		{
			cout << "传输" << endl;
		}
};

class TestUser : public User
{
	public:
	void useProtocol()
	{
		cout << "使用了" << endl;
		for (const auto& it : m_list)
			it->transfer(it);
	}
};
int main()
{

	TestProtocol t1, t2;
	TestUser user;
	user.addProtocol(&t1);
	user.addProtocol(&t2);
	user.useProtocol();
	return 0;
}
