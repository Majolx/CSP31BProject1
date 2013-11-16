#include <iostream>
#include "AddressType.h"
#include <string.h>

using namespace std;

	void AddressType::setAddress(string strAddr, string c, string st, string z){
	streetAddress = strAddr;
	city = c;
	state = st;
	zipCode = z;
}
	string AddressType::getAddress(string strAddr&, string c&, string st&, string z&){

}
	void AddressType::print()const{
	cout << streetAddress << endl << city << ", " << state << " " << zipCode << endl;
}
	AddressType::AddressType(){
	streetAddress = "";
	city = "";
	state = "";
	zipCode = "";
}
	AddressType::AddressType(string strAddr, string c, string st, string z){
	streetAddress = strAddr;
	city = c;
	state = st;
	zipCode = z;

}