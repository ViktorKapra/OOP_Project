#pragma once
#include "Date.h"
#include <fstream>
#include<iostream>
#include <ctime>
#include "../Logic/DynamicArray.hpp"


Date::Date()
{
	year = DEFAULT_YEAR;
	month = DEFAULT_MONTH;
	day = DEFAULT_DAY;
}
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
bool operator>(Date const& first, Date const& second)
{
	if (first.year > second.year) { return true; }
	else if (first.year < second.year) { return false; }

	if (first.month > second.month) { return true; }
	else if (first.month < second.month) { return false; }

	if (first.day > second.day) { return true; }
	else { return false; }

}
bool operator<(Date const& first, Date const& second)
{
	return second > first;
}
bool operator==(Date const& first, Date const& second)
{
	return first.day == second.day &&
		first.month == second.month &&
		first.year == second.year;
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
			if (_year % 400 == 0) { return true; }
			else return false;
		}
		else { return true; }
	}
	else { return false; }
}
void Date::write(std::ofstream& os)const
{
	os.write((char*)&day, sizeof(int));
	os.write((char*)&month, sizeof(int));
	os.write((char*)&year, sizeof(int));
}
void Date::read(std::ifstream& is)
{
	int _day = 0, _month = 0, _year = 0;
	is.read((char*)&_day, sizeof(int));
	is.read((char*)&_month, sizeof(int));
	is.read((char*)&_year, sizeof(int));
	this->setYear(_year);
	this->setMonth(_month);
	this->setDay(_day);
}
void swapDates(Date& first, Date& second)
{
	Date temp = first;
	first = second;
	second = temp;
}

void sortDates(DynamicArray<Date>& dates)
{
	unsigned datesCount = dates.getSize();
	for (int i = 0; i < datesCount - 1; i++)
	{
		Date minn = dates[i];
		int indexMinn = i;
		for (int y = i + 1; y < datesCount; y++)
		{
			if (minn < dates[i])
			{
				minn = dates[i];
				indexMinn = i;
			}
			swapDates(dates[indexMinn], dates[i]);
		}
	}
}

Date Date::getCurrentDate()
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	Date result(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
	return result;
}
std::istream& operator>>(std::istream& is, Date& date)
{
	char sep = '-';
	is >> date.year >> sep >> date.month >> sep >> date.day;
	return is;
}
std::ostream& operator<<(std::ostream& os, Date& date)
{
	os << date.year << "-" << date.month << "-" << date.day;
	return os;
}