#include "Product.h"
#include "IdGenerator.h"
#include <fstream>

Product::Product()
{
	id = 1;
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
	of << product.id << " " << std::endl 
		<< product.name.getText()<< " " << std::endl 
		<< product.manifacturer.getText()<< " " << std::endl 
		<< product.comment.getText() << std::endl;
	return of;
}
std::istream& operator>>(std::istream& is, Product& product)
{
	char data[100];
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
