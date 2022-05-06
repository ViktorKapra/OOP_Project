#pragma once
#include "TextContainer.h"
#include <ctime>

class Product
{
private:
	TextContainer name;
	time_t expiryDate;
	time_t dateOfArrival;
	TextContainer manifacturer;
	int Id;


public:
	Product(char const* _name, time_t _expiryDate,
		time_t _dateOfArrival, char const* manifacturer);
	void setName(char const*);
	void setManifacturer(char const*);
	char const* getName()const { return name.getText(); }
	char const* getManifacturer(){ return manifacturer.getText(); }

};
