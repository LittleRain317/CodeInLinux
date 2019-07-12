#include "transceiver.h"

class TestTransceiver : public Transceiver
{
	public:
		void transfer(Protocol* transceiver)
		{
			((TestTransceiver*)transceiver)->receive(send());
		}

		void divide()
		{
			return;
		}
};

int main()
{
	TestTransceiver t;
	t.copy(TestTransceiver::fromMsg);
	t.send();
	t.receive('b');
	t.divide();
	t.addQueue(TestTransceiver::fromRec);
	t.addToSend();
	t.addToRec();
	t.rmPacketInQueue(TestTransceiver::fromMsg);
	t.rmFromSend();
	t.rmFromRec();
	return 0;
}
