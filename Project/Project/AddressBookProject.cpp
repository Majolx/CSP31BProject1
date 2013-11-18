#include <iostream>
#include <string>
#include <sstream>
#include "AddressBookType.h"
#include "ExtPersonType.h"

#define ENTRY_SIZE 8


using namespace std;

void showMenu();
void resetInput();
void optionOne();
void optionTwo();
void optionThree();
void optionFour();
void optionFive();
void optionSix();
void optionSeven();

int main()
{
	AddressBookType<ExtPersonType> addressBook;
	ifstream inFile;
	inFile.open("data.txt", ifstream::in);

	if (inFile.is_open())
	{
		while (inFile.good())
		{

			// Entries are read in this format.
			string firstName, lastName;
			int month, day, year;
			string street;
			string city;
			string state;
			string zipCode;
			string phoneNumber;
			string status;


			string line[ENTRY_SIZE];
			for (int i = 0; i < ENTRY_SIZE; i++)
			{
				getline(inFile, line[i]);
				cout << line[i];
				/*
				if (!getline(inFile, line[i]))
				{
					cout << "Error: Incorrect Entry Format (" << i << ")" << endl;
					system("PAUSE");
					return 2;
				}*/
			}

			istringstream iss(line[0]);
			iss >> firstName >> lastName;

			iss.clear();
			iss.str(line[1]);
			iss >> month >> day >> year;

			street = line[2];

			iss.clear();
			iss.str(line[3]);
			iss >> city;

			iss.clear();
			iss.str(line[4]);
			iss >> state;

			iss.clear();
			iss.str(line[5]);
			iss >> zipCode;

			iss.clear();
			iss.str(line[6]);
			iss >> phoneNumber;

			iss.clear();
			iss.str(line[7]);
			iss >> status;

			ExtPersonType person(firstName, lastName, 
								 month, day, year, 
								 street, city, state, zipCode, 
								 phoneNumber, status);
			
			person.print();
			//person.printInfo();
			cout << "BR" << endl;
			//addressBook.insert(person);
		}
	}
	else
	{
		cout << "Error: File Not Found" << endl;
		system("PAUSE");
		return 1;
	}

	int userSelection = 0;

	while (userSelection != 8)
	{
		cout << "Welcome to the address book program." << endl << endl;
		cout << "Choose among the following options." << endl << endl;

		showMenu();

		for (;;)
		{
			cout << "Your choice : ";
			if (cin >> userSelection)
			{
				if (userSelection >= 1 && userSelection <= 8)
				{
					break;
				}
				else
				{
					cout << "Please pick a number between 1 and 8!" << endl;
					resetInput();
				}
			}
			else
			{
				cout << "Please, use only integers to select an option." << endl;
				resetInput();
			}
		}

	
		switch(userSelection)
		{
		case 1:
			//See if person is in address book
			optionOne();
			break;
		case 2:
			// Print a person's full info
			optionTwo();
			break;
		case 3:
			// Print people with birthday in specified month
			optionThree();
			break;
		case 4:
			// Print people between two last names
			optionFour();
			break;
		case 5:
			// Print people of a particular status
			optionFive();
			break;
		case 6:
			// Print the entire address book
			optionSix();
			break;
		case 7:
			// Save data
			optionSeven();
			break;
		case 8:
			// Terminate program
			break;
		default:
			break;

		}
	}


	system("PAUSE");
	return 0;
}


void showMenu()
{
	cout << "1: To see if a person is in the address book" << endl;
	cout << "2: Print the information of a person" << endl;
	cout << "3: Print the names of a person having a birthday in a particular month" << endl;
	cout << "4: Print the names of persons between two last names" << endl;
	cout << "5: Print the names of person having a particular status" << endl;
	cout << "6: Print the address book" << endl;
	cout << "7: Save data" << endl;
	cout << "8: Terminate the program" << endl;
	cout << endl;
}

void optionOne()
{
	string lastName;
	for (;;)
	{
		cout << "Enter the last name of the person: ";
		if (cin >> lastName)
		{
			return;
		}
		else
		{
			cout << "Invalid input!" << endl;
			resetInput();
		}
	}
}

void optionTwo()
{
}

void optionThree()
{
}

void optionFour()
{
}

void optionFive()
{
}

void optionSix()
{
}

void optionSeven()
{
}

void resetInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}	