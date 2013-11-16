/*	Class DateType has three private data components ( month, day, and year) all of the type int.  
	The program has setDate, getmonth, 
*/
#ifndef H_DateType
#define H_DateType
#include <iostream>

using namespace std;

class DateType
{
public:
	void setDate(int *month, int *day, int *year); 
	//set member variables month, day, and year

	int getDay() const;
	//return day

	int getMonth() const;
	//return month

	int getYear() const;
	//return year

	void printDate() const;
	//print the date in the format: dMonth-dDay-dYear

	DateType(int month, int day, int year);
	//defalt constructor

	DateType();
	// constructor
private:
	int month;
	int day;
	int year;
	
	bool isLeapYear();
	//check if year is a leap year
};
#endif