#ifndef _TRANSCEIVER_PROTOCOL_H_
#define _TRANSCEIVER_PROTOCOL_H_

#include "../Observer/protocol.h"

#define _DEBUG_
class Transceiver : public Protocol
{
	#ifndef _DEBUG_
	protected:
	#else
	public:
	#endif
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
	#ifndef _DEBUG_
	protected:
	#else
	public:
	#endif
		virtual void copy(Direction dir);	
		virtual Byte send();
		virtual void receive(Byte data);
		virtual Packet reply(); //响应	
		virtual void divide() = 0; 
		virtual void addQueue(Direction dir);
		virtual void addToSend();
		virtual void addToRec();		
		virtual void rmPacketInQueue(Direction dir);
		virtual void rmFromSend();
		virtual void rmFromRec();
		virtual void setReplyMsg() = 0;
	public:
		virtual ~Transceiver() { }
		virtual void transfer(Protocol* transceiver) = 0;
};

#endif
