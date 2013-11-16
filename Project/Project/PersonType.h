#ifndef _PersonType_H
#define _PersonType_H

#include <string>
#include <iostream>

using namespace std;

class PersonType
{
private:
	string firstName;
	string lastName;
public:
	void setName(string f, string l);
	string getFirstName() const;
	string getLastName() const;
	void getName(string *f, string *l) const;
	void print() const;

	PersonType();
	PersonType(string f, string l);
};

#endif