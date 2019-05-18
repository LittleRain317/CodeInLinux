#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
unsigned int i = 0U;
class Employee
{
	private:
		string name;
		unsigned id;
	public:
		Employee() : name(string()), id(i) { ++i; }
		Employee(string n) : name(n), id(i) { ++i; }
		Employee(const Employee & em) : name(em.name), id(i) { ++i; }
		Employee& operator= (const Employee & t)
		{
			name = t.name;
			id = i;
			++i;
			return *this;
		}
};

int main()
{
	return 0;
}
