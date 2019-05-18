#include "Person.h"

istream & read(istream & is, Person & person)
{
	is >> person.m_name >> person.m_address;
	return is;
}

ostream & print(ostream & os, const Person & person)
{
	os << person.m_name << " " << person.m_address;
	return os;
}
