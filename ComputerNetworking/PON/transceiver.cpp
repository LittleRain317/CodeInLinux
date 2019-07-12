#include "transceiver.h"

void Transceiver::CopyData(int source)
{
	if (source == TheQueue)
	{
		if (m_dataQueue.empty())
		{
			return;
		}
		packet copy =  m_dataQueue.front();
		swap(copy, m_toBeSentData);
	}
	else if (source == SendingData)
	{
		if (m_toBeSentData.empty())
			return;
		m_dataQueue.push_front(m_toBeSentData);
	}
}

void Transceiver::Receive(const byte& one) 
{
	if (m_dataQueue.empty() || m_dataQueue.back().back() == static_cast<byte>(ReceiveEnd))
	{
		packet newData;
		newData.push_back(one);
		m_dataQueue.push_back(newData);
		return;
	}	
	else
	{
		m_dataQueue.back().push_back(one);	
	}	
}


Transceiver::byte Transceiver::Send()
{
	if (m_dataQueue.empty()) 
	{	
		finishSend = false;
		return static_cast<byte>(EmptyQueue);
	}
	if (m_dataQueue.front().empty())  
	{
		finishSend = true;
		m_dataQueue.pop_front();	
		return static_cast<byte>(SendEnd);
	}
	auto temp = m_dataQueue.front().front();
	m_dataQueue.front().pop_front();
	return temp;
}

void Transceiver::AddIpToData()
{
	if (m_dataQueue.empty())
		return;
	m_dataQueue.front().push_front(' ');
	auto copyIp = m_Ip;
	reverse(copyIp.begin(), copyIp.end());
	for (const auto& each : copyIp)
	{
		m_dataQueue.front().push_front(each);
	}
}

void Transceiver::RemoveIpFromData(packet& data)
{
	data.assign(find(data.begin(), data.end(), ' ') + 1, data.end()); 
}

bool Transceiver::CheckIntegrity(const packet& receiveCopy) const
{
	return m_toBeSentData == receiveCopy;
}

bool Transceiver::Transfer(Transceiver& receiver)
{
	srand(static_cast<size_t>(time(nullptr)));
	bool finishCheck = false;
	packet receiveCopy;
	while (!finishCheck)
	{
		AddIpToData();
		CopyData(TheQueue);
		while (!finishSend)
		{
			bool exception = rand() % 100 > 89 ? true : false;
			auto data = Send();
			if (data == static_cast<byte>(SendEnd))
				break;
			if (data == static_cast<byte>(EmptyQueue))
				return false;
			if (exception)
				continue;
			else
				receiveCopy.push_back(data);
		}
		if (!CheckIntegrity(receiveCopy))
		{
			receiveCopy.clear();
			RemoveIpFromData(m_toBeSentData);
			CopyData(SendingData);
			finishSend = false;
		}
		else
		{
			RemoveIpFromData(receiveCopy);
			finishCheck = true;
			finishSend = false; 
			m_toBeSentData.clear();
			for (const auto& oneByte : receiveCopy)
				receiver.Receive(static_cast<byte>(oneByte));
		}
	}
	return true;
}
