#ifndef _OBSERVER_USER_H_
#define _OBSERVER_USER_H_

#include <vector>
using std::vector;

class Protocol;
class User
{
	public:
		vector<Protocol*> m_list;
	public:
		virtual void useProtocol() = 0;
		virtual	void addProtocol(Protocol* protocol)
		{
			m_list.push_back(protocol);
		}
		virtual void rmProtocol()
		{
			if (!m_list.empty())
				m_list.pop_back();
		}
		virtual ~User() { }
};

#endif
