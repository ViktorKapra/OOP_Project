#include "Date.h"
#include <fstream>
#include<iostream>


void Date::setDay(int _day)
{
	if (_day < 1 || _day>31)
	{
		std::cerr << "Day must be a number between 1 and 31!" << std::endl;
	}
	switch (month)
	{
	case 4: case 6: case 9: case 11:
	{
		if (_day == 31)
		{
			std::cerr << "Invalid day to given month" << std::endl;
			return;
		}

	}break;
	case 2:
	{
		if (IsLeapYear(year))
		{
			if (_day > 28)
			{
				std::cerr << "Invalid day to given month" << std::endl;
				return;
			}
		}
		else
		{
			if (_day > 27)
			{
				std::cerr << "Invalid day to given month and year" << std::endl;
				return;
			}
		}

	}break;
	default:
	{ }
	break;
	}
	day = _day;
}
void Date::setMonth(int _month)
{
	if (_month > 12 || _month < 1)
	{
		std::cerr << "Month must be number between 1 and 12! " << std::endl;
	}
	month = _month;
}
void Date::setYear(int _year)
{
	if (_year <= 0)
	{
		std::cerr << "Year must be positive number" << std::endl;
	}
	year = _year;
}
bool Date::operator>(Date& date) 
{
	if (this->year > date.year) { return true; }
	else if(this->year< date.year) { return false; }

	if (this->month > date.month) { return true; }
	else if (this->month < date.month) { return false; }

	if (this->day > date.day) { return true; }
	else{ return false; }
	
}
bool Date::operator<(Date& date) 
{
	return date > *this;
}
bool Date::operator==(Date& date) 
{
	return this->day == date.day &&
		this->month == date.month &&
		this->year == date.year;
}
Date::Date(int _day, int _month, int _year)
{
	setYear(_year);
	setMonth(_month);
	setDay(_day);
}
bool Date::IsLeapYear(int _year)
{
	if (_year % 4 == 0)
	{
		if (_year % 100 == 0)
		{
			if (_year % 400 == 0){ return true; }
			else return false;
		}
		else { return true; }
	}
	else { return false; }
}
void Date::print(std::ofstream&, Date) {}