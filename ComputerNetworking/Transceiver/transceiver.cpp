#include "transceiver.h"

Transceiver::Byte Transceiver::send()
{
	if (m_curSendPacket.empty())
		return empty;
	Byte temp = m_curSendPacket.front();
	m_curSendPacket.pop_front();
	return temp;
}

void Transceiver::receive(Transceiver::Byte data)
{
	m_curRecPacket.push_back(data);
}

Transceiver::Packet Transceiver::reply()
{
	return m_reply;
}

void Transceiver::copy(Transceiver::Direction dir)
{
	if (dir == fromMsg)
	{
		if (m_msgQueue.empty())
		{
			return;
		}
		m_curSendPacket = m_msgQueue.front();
	}
	else if (dir == fromRec)
	{
		if (m_curRecPacket.empty())
		{
			return;
		}
		m_receiveQueue.push_back(m_curRecPacket);
	}
}
