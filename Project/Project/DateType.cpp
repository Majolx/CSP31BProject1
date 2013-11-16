#include <iostream>
#include "DateType.h"

using namespace std;
DateType::DateType(){
	int month = 1;
	int day = 1;
	int year = 1900;
}
DateType::DateType(int m, int d, int y){
	month = m;
	day = d;
	year = y;
}
void DateType::setDate(int m, int d, int y){
	month = m;
	day = d;
	year = y;
}
int DateType::getDay() const{
	return day;
}
int DateType::getMonth() const{
	return month;
}
int DateType::getYear() const{
	return year;
}
void DateType::printDate() const{
	cout << month <<"/" << day << "/" << year << endl;
}
bool DateType::isLeapYear() const{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}