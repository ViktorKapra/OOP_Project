#ifndef _DATE_HPP
#define _DATE_HPP


#include "DynamicArray.hpp"
#include <fstream>

const int  DEFAULT_DAY = 18;
const int DEFAULT_MONTH = 8;
const int DEFAULT_YEAR = 2002;

class Date {
private:
	int day;
	int month;
	int year;
	bool IsLeapYear(int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
public:
	friend bool operator>(Date const& first, Date const& second);
	friend bool operator<(Date const& first, Date const& second);
	friend bool operator==(Date const& first, Date const& second);
	Date();
	Date(int _day, int _month, int _year);
	void write(std::ofstream&)const;
	void read(std::ifstream&);
};
 //bool operator>(Date const& first,Date const& second);
 //bool operator<(Date const& first, Date const& second);
 //bool operator==(Date const& first, Date const& second);

 void swapDates(Date& first, Date& second);
 void sortDates(DynamicArray<Date>& dates);
#endif // !_DATE
