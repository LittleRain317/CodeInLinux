#include "UDP.h"

void UDP::addPort(uint16_t src, uint16_t dest)
{
	memcpy(packet, &src, 2);
	memcpy(&packet[2], &dest, 2);	
}

UDP::UDP(const deque<Byte>& data)
{
	auto index = dataBeginPos;
	for (const auto& it : data)
	{
		if (index != 
		packet[index++] = it;
	}
}
