#ifndef _TRANSCEIVER_PROTOCOL_H_
#define _TRANSCEIVER_PROTOCOL_H_

#include "../Observer/protocol.h"

class Transceiver : public Protocol
{
	protected:
		enum Status
		{
			empty
		};
		enum Direction
		{
			fromMsg,
			fromRec		
		};
	protected:
		deque<Packet> m_msgQueue;//发送队列
		deque<Packet> m_receiveQueue;//接收队列
		Packet m_curSendPacket; //当前要发送的分组
		Packet m_curRecPacket; //当前接收到的分组
		Packet m_curComPacket; //当前要提交给上层的分组
		Packet m_reply; //回应分组	
	protected:
		virtual void copy(Direction dir);	
		virtual Byte send();
		virtual void receive(Byte data);
		virtual Packet reply(); //响应	
		virtual Packet divide() = 0; 
	public:
		virtual ~Transceiver() { }
		virtual void transfer(Protocol* transceiver) = 0;
};

#endif
