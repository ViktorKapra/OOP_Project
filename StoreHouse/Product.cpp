#include "Product.h"
#include "IdGenerator.h"
#include <fstream>


Product::Product(char const* _name, char const* _manifacturer, char const* _comment)
{
	setName(_name);
	setManifacturer(_manifacturer);
	setComment(_comment);
	id = IdGenerator().GetId();
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
void Product::print(std::ofstream& of)
{
	of << id << " " << name.getLenghtOfText() << name.getText()
		<< " " << manifacturer.getLenghtOfText() << manifacturer.getText()
		<< " " << comment.getLenghtOfText() << comment.getText()<<std::endl;
}
