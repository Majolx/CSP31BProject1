#ifndef H_AddressType
#define H_AddressType
#include <iostream>
#include <string>

using namespace std;

class AddressType
{
public:
	void setAddress(string, string, string, string);
	//set member variables streetAddress, city, state, zipcode

	void getAddress(string &streetAddress, string &city, string &state, string &zipCode);
	//return address

	void print()const;
	//print the address in the format: 
	//streetAddress
	//city, state zipcode

	AddressType();
	//constructor

	AddressType(string &streetAddress, string &city, string &state, string &zipCode);
	//defalt constructor

private:
	string streetAddress;
	string city;
	string state;
	string zipCode;
}
#endif