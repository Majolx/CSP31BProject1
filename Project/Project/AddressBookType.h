/**
 * AddressBookType.h
 * [Insert Description of File]
 *
 * Written by:  Mathew Larribas
 * Date:        11/13/2013
 ******************************************************************************/
#include <iostream>
#include "arrayListType.h"

using namespace std;

template <class elemType>
class AddressBookType<elemType> : public arrayListType
{
public:
    void print();
    void printNameInTheMonth(int);
    int search(string);
    void printInfoOf(string);
    void printNamesWithStatus(string);
    void printAt(int);
    void printNamesBetweenLastNames(string, string);
    void saveData(&ofstream);

    AddressBookType();
};

// ========================================================================== //
// Constructor - Default
template <class elemType>
AddressBookType<elemType>::AddressBookType() : length(0)
{   
}

// ========================================================================== //
// Print - Default
template <class elemType>
void AddressBookType<elemType>::print()
{
    for each (ExtPersonType person in this->list)
    {
       person.printInfo();
    }
}

// --------------------------------------------------------------
// Print - Name In The Month
template <class elemType>
void AddressBookType<elemType>::printNameInTheMonth(int month)
{
    for each (ExtPersonType person in this->list)
    {
        if (person.getMonth() == month)
        {
            person.print();
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
    for each (ExtPersonType person in this->list)
    {
        if (person.getStatus() == status)
            person.print();
    }
}

// --------------------------------------------------------------
// Print - Print At
template <class elemType>
void AddressBookType<elemType>::printAt()(int index)
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
    cout << s1[0] << endl;
}

// ========================================================================== //
// Search
template <class elemType>
int AddressBookType<elemType>::search(string lastName)
{
    int count = 0;
    for each (ExtPersonType person in this->list)
    {
        if (person.getLastName() == lastName)
            return count;
        count++;
    }
    return -1;
}