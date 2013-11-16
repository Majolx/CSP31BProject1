#include "ExtPersonType.h"
#include <iostream>
#include <string>

using namespace std;

void ExtPersonType::printAddress() const
{
	PersonType p;

	p.print();
	address.print();
}

void ExtPersonType::printInfo() const
{
	PersonType p;
	
	p.print();
	dob.print();
	cout << "Phone Number: " << phoneNumber << endl <<
		"Person Type: " << personStatus << endl;
	address.print();
}

void ExtPersonType::setInfo(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phoneN, string stat)
{
	PersonType name;

	name.setName(f, l);
	dob.setDate(m, d, y);
	address.setAddess(street, city, state, zipcode);
	phoneNumber = phoneN;
	personStatus = stat;
}

void ExtPersonType::setInfo(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phoneN, string stat)
{
	PersonType name;

	name.setName(f, l);
	dob.setDate(m, d, y);
	address.setAddess(street, city, state, zipcode);
	phoneNumber = "";
	personStatus = "";
}

ExtPersonType::ExtPersonType(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phoneN, string stat)
{
	PersonType name;

	name.setName(f, l);
	dob.setDate(m, d, y);
	address.setAddess(street, city, state, zipcode);
	phoneNumber = phoneN;
	personStatus = stat;
}

string ExtPersonType::getStatus() const
{
	return personStatus;
}