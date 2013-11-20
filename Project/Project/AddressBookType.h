/**
 * AddressBookType.h
 * [Insert Description of File]
 *
 * Written by:  Mathew Larribas
 * Date:        11/13/2013
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include "arrayListType.h"
#include "orderedLinkedList.h"

using namespace std;

template <class elemType>
class AddressBookType : public orderedLinkedList<elemType>
{
public:
    void print();
    void printNameInTheMonth(int);
    int search(string);
    void printInfoOf(string);
    void printNamesWithStatus(string);
    void printAt(int);
    void printNamesBetweenLastNames(string, string);
	void printNamesWithBirthday(int);
    void saveData(ofstream&);
	bool lexicalCompare(string, string);


    AddressBookType();
};

// ========================================================================== //
// Constructor - Default
template <class elemType>
AddressBookType<elemType>::AddressBookType()
{   
	length = 0;
}

// ========================================================================== //
// Print - Default
template <class elemType>
void AddressBookType<elemType>::print()
{
    for (int i = 0; i < length; i++)
    {
       list[i].printInfo();
	   cout << endl;
    }
}

// --------------------------------------------------------------
// Print - Name In The Month
template <class elemType>
void AddressBookType<elemType>::printNameInTheMonth(int month)
{
    for (int i = 0; i < this->length; i++)
    {
        if (list[i].getMonth() == month)
        {
            list[i].print();
        }
    }
}

// --------------------------------------------------------------
// Print - Info Of
template <class elemType>
void AddressBookType<elemType>::printInfoOf(string lastName)
{
    int index = search(lastName);

    if (index != -1)
    {
        this->list[index].printInfo();
    }
}

// --------------------------------------------------------------
// Print - Names with Status
template <class elemType>
void AddressBookType<elemType>::printNamesWithStatus(string status)
{
    for (int i = 0; i < this->length; i++)
    {
        if (list[i].getStatus() == status)
            list[i].print();
    }
}

// --------------------------------------------------------------
// Print - Print At
template <class elemType>
void AddressBookType<elemType>::printAt(int index)
{
    if (this->list[index] != NULL)
    {
        this->list[index].printInfo();
    }
}

// --------------------------------------------------------------
// Print - Print Names Between Last Names
template <class elemType>
void AddressBookType<elemType>::printNamesBetweenLastNames(string s1, string s2)
{
	for (int i = 0; i < this->length; i++)
	{
		if (lexicalCompare(list[i].getLastName(), s1) && lexicalCompare(s2, list[i].getLastName()))
		{
			list[i].print();
		}
	}
}

template <class elemType>
bool AddressBookType<elemType>::lexicalCompare(string s1, string s2)
{
	if (s1 == s2) return true;

	int i = 0;
	for (;;)
	{
		if (NULL == s1[i]) return false;
		if (NULL == s2[i]) return true;

		char a, b;
		a = tolower(s1[i]);
		b = tolower(s2[i]);

		if (a < b) return false;
		if (b < a) return true;

		i++;
	}
}

template <class elemType>
void AddressBookType<elemType>::printNamesWithBirthday(int month)
{
	for (int i = 0; i < this->length; i++)
	{
		if (list[i].getDate().getMonth() == month)
			list[i].print();
	}
}

// ========================================================================== //
// Search
template <class elemType>
int AddressBookType<elemType>::search(string lastName)
{
    int count = 0;
	for (int i = 0; i < this->length; i++)
	{
		if (list[i].getLastName() == lastName)
			return count;
		count++;
	}
    return -1;
}

// ========================================================================== //
// Save Data
template <class elemType>
void AddressBookType<elemType>::saveData(ofstream& outFile)
{
	for (int i = 0; i < this->length; i++)
	{
		DateType d = list[i].getDate();
		AddressType a = list[i].getAddress();
		string aMembers[4];
		a.getAddress(aMembers[0], aMembers[1], aMembers[2], aMembers[3]);

		outFile << list[i].getFirstName() << " " << list[i].getLastName() << endl;
		outFile << d.getMonth() << " " << d.getDay() << " " << d.getYear() << endl;
		outFile << aMembers[0] << endl;
		outFile << aMembers[1] << endl;
		outFile << aMembers[2] << endl;
		outFile << aMembers[3] << endl;
		outFile << list[i].getPhoneNumber() << endl;
		outFile << list[i].getStatus();
		if (i + 1 != this->length)
			outFile << endl;
	}
}
