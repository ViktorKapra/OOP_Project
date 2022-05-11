#pragma once
#include "TextContainer.h"
#include <ctime>
#include <fstream>
class Product
{
private:
	int id;
	TextContainer name;
	TextContainer manifacturer;
	TextContainer comment;
public:
	Product(char const* _name, char const* _manifacturer,char const* _comment);
	void setName(char const*);
	void setManifacturer(char const*);
	void setComment(char const*);
	int getId()const { return id; }
	char const* getName()const { return name.getText(); }
	char const* getManifacturer()const{ return manifacturer.getText(); }
	char const* getComment()const { return comment.getText(); }
	void print(std::ofstream& of);
	//friend 
};

