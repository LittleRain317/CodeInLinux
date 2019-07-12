#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
class Object
{
	private:
		std::string m_name = "NULL";
	public:
		std::string getName() { return m_name; }
};
#endif //end
