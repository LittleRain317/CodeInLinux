#include "transceiver.h"

class TestTransceiver : public Transceiver
{
	public:
		void transfer(Protocol* transceiver)
		{
			((TestTransceiver*)transceiver)->receive(send());
		}

		Packet divide()
		{
			return deque<Byte>();
		}
};

int main()
{
	TestTransceiver t;
	t.divide();
	t.transfer(&t);
	return 0;
}
