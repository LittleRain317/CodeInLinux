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
		m_curRecPacket = m_receiveQueue.front();
	}
}

void Transceiver::addQueue(Transceiver::Direction dir)
{
	if (dir == fromMsg)
	{
		addToSend();
	}
	else if(dir == fromRec)
	{
		addToRec();
	}
}

void Transceiver::addToSend()
{
	m_msgQueue.push_back(m_curSendPacket);
}

void Transceiver::addToRec()
{
	m_receiveQueue.push_back(m_curRecPacket);
}

void Transceiver::rmPacketInQueue(Transceiver::Direction dir)
{
	if (dir == fromMsg)
	{
		rmFromSend();
	}
	else if(dir == fromRec)
	{
		rmFromRec();
	}
}

void Transceiver::rmFromSend()
{
	if (!m_msgQueue.empty())
		m_msgQueue.pop_front();
}

void Transceiver::rmFromRec()
{
	if (!m_receiveQueue.empty())
		m_receiveQueue.pop_front();
}

