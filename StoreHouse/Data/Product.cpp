//! Class which describes preoduct. (It does not conatin quantities of products!)
#pragma once
#include "Product.h"
#include <fstream>

Product::Product()
{
	id = 1;
}
void Product::setId(int _id)
{
	id = _id;
}
Product::Product(char const* _name, char const* _manifacturer, char const* _comment)
{
	setName(_name);
	setManifacturer(_manifacturer);
	setComment(_comment);
	//id = IdGenerator().GetId();
}
void Product::setName(char const* _name) 
{
	name.setText(_name);
}
void Product::setManifacturer(char const* _manifacturer) 
{
	manifacturer.setText(_manifacturer);
}
void Product::setComment(char const* _comment) 
{
	comment.setText(_comment);
}

std::ostream& operator<<(std::ostream& of, Product const& product)
{
	of << product.id <<  "\n"
		<< product.name.getText() << "\n"
		<< product.manifacturer.getText() << "\n"
		<< product.comment.getText()<<"\n";
	return of;
}
std::istream& operator>>(std::istream& is, Product& product)
{
	char data[100];
	char interval;
	int sizeOfMessage = 100;
	int id = 0;
	is >> product.id;
	is.ignore();
	is.getline(data, sizeOfMessage);
	product.setName(data);
	is.getline(data, sizeOfMessage);
	product.setManifacturer(data);
	is.getline(data, sizeOfMessage);
	product.setComment(data);
	return is;
}
bool operator==(Product const& first, Product const& second)
{
	return first.id == second.id;
}
