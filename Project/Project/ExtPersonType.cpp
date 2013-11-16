#include "ExtPersonType.h"
#include "AddressType.h"
#include "DateType.h"
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

void ExtPersonType::setInfo(string f, string l, AddressType a, DateType d, string phoneN, string stat)
{
	string st, city, state, zip;
	int m, d, y;
	PersonType name;

	name.setName(f, l);
	a.getAddress(st, city, state, zip);
	address.setAddress(st, city, state, zip);
	d.getDate(m, d, y);
	dob.setDate(m, d, y);
	phoneNumber = phoneN;
	personStatus = stat;
}

ExtPersonType::ExtPersonType(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phoneN, string stat)
{
	PersonType name;

	name.setName(f, l);
	dob.setDate(m, d, y);
	address.setAddress(street, city, state, zipcode);
	phoneNumber = phoneN;
	personStatus = stat;
}

string ExtPersonType::getStatus() const
{
	return personStatus;
}

AddressType ExtPersonType::getAddress() const
{
	return address;
}

DateType ExtPersonType::getDate() const
{
	return dob;
}