#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iostream>
using std::istream;
using std::ostream;
using std::string;

class Person;
istream & read(istream & is, Person & person);
ostream & print(ostream & os, const Person & person);

class Person
{
	friend istream & read(istream & is, Person & person);
	friend ostream & print(ostream & os, const Person & person);

private:
	string m_name;
	string m_address;
public:	
	string GetName() const { return m_name; }
	string GetAddress() const { return m_address; }

	Person(string name = "NULL", string address = "NULL") : m_name(name), m_address(address) {}
	Person(istream & is) { read(is, *this); }
};


#endif
