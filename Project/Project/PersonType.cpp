#include "PersonType.h"
#include <string>
#include <iostream>

using  namespace std;

void PersonType::setName(string f, string l)
{
	f = firstName;
	l = lastName;
}

string PersonType::getFirstName() const
{
	return firstName;
}

string PersonType::getLastName() const
{
	return lastName;
}

void PersonType::getName(string *f, string *l) const
{
	*f = firstName;
	*l = lastName;
}

void PersonType::print() const
{
	cout << lastName << " " << firstName << endl;
}

PersonType::PersonType()
{
	firstName = "";
	lastName = "";
}

PersonType::PersonType(string n, string l)
{
	firstName = n;
	lastName = l;
}