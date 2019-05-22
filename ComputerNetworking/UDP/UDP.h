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
		uint16_t m_srcPort = 0;
		uint16_t m_destPort = 0;
		uint16_t m_length = 0;
		uint16_t m_checkSum = 0;
	private:
		bool check() const; //校验检验和
		uint16_t calLength();
		void addLength();
		uint16_t calCheckSum();
		void addCheckSum();
		Packet divide();
	public:
	//	UDP(Packet data, uint16_t srcPort, uint16_t destPort);
		void transfer(Protocol* transceiver);
		~UDP() { } 
};
#endif
