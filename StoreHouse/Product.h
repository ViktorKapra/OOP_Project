#pragma once
#include "TextContainer.h"
#include <ctime>

class Product
{
private:
	int Id;
	TextContainer name;
	TextContainer manifacturer;
	TextContainer comment;
public:
	Product(char const* _name, char const* manifacturer);
	void setName(char const*);
	void setManifacturer(char const*);
	char const* getName()const { return name.getText(); }
	char const* getManifacturer(){ return manifacturer.getText(); }

};
