#ifndef _ExtPersonType_h
#define _ExtPersonType_h

#include "PersonType.h"
#include "AddressType.h"
#include "DateType.h"
#include <iostream>
#include <string>

using namespace std;

class ExtPersonType : public PersonType
{
private:
	string phoneNumber;
	string personStatus;
	AddressType address;
	DateType dob;
public:
	void printAddress() const;
	void printInfo() const;
	void setInfo(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phone, string person);
	void setInfo(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode);
	ExtPersonType(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phone, string person);

	string getStatus() const;
}

#endif