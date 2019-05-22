//不考虑网络层
#ifndef _UDP_UDP_H_
#define _UDP_UDP_H_

#include "../Transceiver/transceiver.h"
#include <cstdint>
#include <cstring>

class UDP : public Transceiver
{

	private://预留20个字节作为IP包头待以后实现
		static const unsigned DataBeginPos = 28;
		static const unsigned MaxLength = 65535;
	private:
		struct SegmentHead
		{
			uint16_t m_srcPort;
			uint16_t m_destPort;
			uint16_t m_length;
			uint16_t m_checkSum;
		};
		enum SendOrReply
		{
			send,
			reply
		};
	private:
		SegmentHead m_SegmentHeadArr[2] = {{0,0,0,0}, {0, 0, 0, 0}};
		Packet m_data; //从上层接收到的数据
	private:
		bool check(SendOrReply which) const; //校验检验和
		bool checkSend();
		bool checkReply();
		
		void setReplyMsg(); //设置回复信息
		uint16_t calLength(SendOrReply which);
		uint16_t calLengthSend();
		uint16_t calLengthReply();

		void addLength(SendOrReply which);
		void addLengthSend();
		void addLengthReply();

		uint16_t calCheckSum(SendOrReply which);
		uint16_t calCheckSumSend();
		uint16_t calCheckSumReply();

		void addCheckSum(SendOrReply which);
		void addCheckSumSend();
		void addCheckSumReply();

		void addPort(SendOrReply which);
		void addPortSend();
		void addPortReply();

		void addData(SendOrReply which);
		void addDataSend();
		void addDataReply();

		void mkPacket(SendOrReply which);
		void mkPacketSend();
		void mkPacketReply();
		void divide();
;
	public:
		UDP(Packet data = deuqe<Byte>(), uint16_t srcPort = 0, uint16_t destPort = 0);
		void transfer(Protocol* transceiver);
		~UDP() { } 
		void setPort(uint16_t srcPort, uint16_t destPort);
		void setData(const Packet& data); 	
};
#endif
