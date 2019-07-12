#ifndef _TRANSCEIVER_H_
#define _TRANSCEIVER_H_

#include <deque>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
using std::deque;
using std::swap;
using std::find;
using std::reverse;
using std::string;
class Transceiver 
{
	public:
		enum {TheQueue, SendingData}; 
		enum status{ReceiveEnd, EmptyQueue, SendEnd };
		using byte = unsigned char;
		using packet = deque<byte>;
		using packetQueue = deque<packet>;
	private:
		packetQueue m_dataQueue = {packet{(byte)'a', (byte)'b', (byte)'c', (byte)0}, packet{(byte)'d', (byte)'e', (byte)'f', (byte)0}};
		// 真实环境删除
		packet m_toBeSentData;
		string m_Ip = string();
		bool finishSend = false;
		
		void AddIpToData();
		void RemoveIpFromData(packet& data);
		byte Send();
		void Receive(const byte& one);
		bool CheckIntegrity(const packet& receiveCopy) const;
		void CopyData(int source);
	public:
		bool Transfer(Transceiver& receiver);
		Transceiver(const string& ip = string()) : m_Ip(ip) { } 
};
#endif
