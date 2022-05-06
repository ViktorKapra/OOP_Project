#pragma once

#include <fstream>

class Date {
private:
	int day;
	int month;
	int year;
public:
	void setDay();
	void setMonth();
	void setYear();
	bool operator>(Date&);
	bool operator<(Date&);
	bool operator==(Date&);
	Date(int, int, int);
	void print(ofstream&, Date);
};



