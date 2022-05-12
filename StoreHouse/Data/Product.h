#pragma once
#include "..\Logic\TextContainer.h"
#include <ctime>
#include <fstream>
#include <fstream>
class Product
{
private:
	int id;
	TextContainer name;
	TextContainer manifacturer;
	TextContainer comment;
public:
	Product();
	Product(char const* _name, char const* _manifacturer,char const* _comment);
	void setName(char const*);
	void setManifacturer(char const*);
	void setComment(char const*);
	void setId(int _id);
	int getId()const { return id; }
	char const* getName()const { return name.getText(); }
	char const* getManifacturer()const{ return manifacturer.getText(); }
	char const* getComment()const { return comment.getText(); }
	friend std::ostream&  operator<<(std::ostream& of,Product const& product);
	friend std::istream& operator>>(std::istream& is, Product& product);
	//friend 
};

