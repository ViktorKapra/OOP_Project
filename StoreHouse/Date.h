#pragma once

#include <fstream>

class Date {
private:
	int day;
	int month;
	int year;
	bool IsLeapYear(int);
public:
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	bool operator>(Date&);
	bool operator<(Date&);
	bool operator==(Date&);
	Date(int _day, int _month, int _year);
	void print(std::ofstream&, Date);
};



