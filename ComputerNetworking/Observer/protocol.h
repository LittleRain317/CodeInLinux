#ifndef _OBSERVER_PROTOCOL_H_
#define _OBSERVER_PROTOCOL_H_

#include <deque>
using std::deque;

class Protocol
{
	public:
		using Byte = unsigned char;
                using Packet = deque<Byte>;
		virtual ~Protocol() { }
		virtual void transfer(Protocol* protocol) = 0; 
};

#endif

