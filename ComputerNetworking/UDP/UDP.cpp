#include "UDP.h"

bool UDP::check() const
{
	if(m_curRecPacket.empty())	
		return false;
	uint16_t sum = 0;
	for (size_t index = 0U; index != 8; ++index)
	{
		auto temp1 = m_curRecPacket[index];
		auto temp2 = m_curRecPacket[index + 1];
		uint16_t twoByteSum = 0;
		Byte* pByte = reinterpret_cast<Byte *>(&twoByteSum);	
		memcpy(pByte, &temp1, 1);
	       	memcpy(pByte + 1, &temp2, 1);
		sum += twoByteSum;
	}
	if (sum == 0)
	{
		return true;
	}	
	else
	{
		return false;
	}
}

void UDP::transfer(Protocol* transceiver)
{
	return;
}

Protocol::Packet UDP::divide()
{
	return deque<Byte>();
} 

