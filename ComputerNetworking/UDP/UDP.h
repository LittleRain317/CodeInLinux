#ifndef UDP_H_
#define UDP_H_

#include <cstdint>
#include <deque>
#include <cmemory>

using std::deque;

class UDP
{
public:
	using Byte = unsigned char;
	using Packet = Byte [32];
	const unsigned dataBeginPos = 8;
	const unsigned dataEndPos = 
private:
	Packet packet;
public:
	void addPort(uint16_t src, uint16_t dest);
	void autoFullLength();
	void autoFullCheckSum();
	deque<Byte> getData() const;
	UDP(const deque<Byte>& data);
};
#endif
