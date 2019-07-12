#include "UDP.h"
#include <iostream>
#include <stdexcept>

void UDP::setReplyMsg()
{
	//拷贝接收方的端口号和本端口号
	//添加回复信息
	for(size_t index = 0; index != 4; ++index)
	{	
		m_reply.push_back(m_curRecPacket[index]);
	}
	//添加检验和以及长度
}

bool UDP::check(SendOrReply which) const
{
	if(m_curRecPacket.empty())	
		return false;
	uint16_t sum = 0;
	for (size_t index = 0U; index != 8; index += 2)
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

uint16_t UDP::calLength(SendOrReply which)
{
	return m_data.size() + 28;
}

void UDP::addLength(SendOrReply which)
{
	Byte* pByte = reinterpret_cast<Byte*>(&m_length);
	m_curSendPacket.push_back(*pByte);
	m_curSendPacket.push_back(*(pByte + 1));
}

uint16_t UDP::calCheckSum(SendOrReply which)
{
	m_checkSum = ~(m_srcPort + m_destPort + m_length);
}

void UDP::addCheckSum(SendOrReply which)
{
	Byte* pByte = reinterpret_cast<Byte*>(&m_checkSum);
	m_curSendPacket.push_back(*pByte);
	m_curSendPacket.push_back(*(pByte + 1));
}

void UDP::addPort(SendOrReply which)
{
	Byte* pByte = reinterpret_cast<Byte *>(&m_srcPort);
	m_curSendPacket.push_back(*pByte);
	m_curSendPacket.push_back(*(pByte + 1));
	pByte = reinterpret_cast<Byte *>(&m_destPort);
	m_curSendPacket.push_back(*pByte);
	m_curSendPacket.push_back(*(pByte + 1));
}

void UDP::addData(SendOrReply which)
{
	for(const auto& it : m_data)
	{
		if (m_curSendPacket.size() == MaxLength)
			break;
		else
			m_curSendPacket.push_back(it);
	}	
}

void UDP::mkPacket(SendOrReply which)
{
	try{
		if (!(m_srcPort || m_destPort))
		throw std::logic_error("未设置端口号");
		if (m_data.empty())
		throw std::logic_error("未添加发送数据");
	}
	catch (std::logic_error e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	addPort();
	addLength();
	addCheckSum();
	addData();
}

void UDP::divide()
{
	for(size_t index = DataBeginPos; index != m_curRecPacket.size(); ++index)
	{
		m_curComPacket.push_back(m_curRecPacket[index]);
	}		
}


void UDP::transfer(Protocol* transceiver)
{
	//制作分组
	mkPacket();	
	//将分组添加到发送队列
	addQueue(fromMsg);
	//发送发送队列中的分组
	//接收方接收分组
	//接收方检验检验和
	//检验无误则添加到接收队列中
	//将接收队列的分组上传给上层
	//反馈正确
	//检验有误时则发送反馈失败
	//发送方重新发送	

}


