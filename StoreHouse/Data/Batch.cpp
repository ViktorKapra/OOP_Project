#pragma once
#include "Batch.h"
#include <iostream>

Batch::Batch()
{

}
Batch::Batch(unsigned _productId, Date _expiryDate, Date _dateOfArival, unsigned _quantity):productId(_productId),
expiryDate(_expiryDate),dateOfArrival(_dateOfArival)
{
	if (_quantity == 0)
	{
		std::cerr << "Quantity can not be 0" << std::endl;
	}
	else { quantity = _quantity; }
}
void Batch::read(std::ifstream& is)
{
	is.read((char*)&productId, sizeof(unsigned));
	is.read((char*)&quantity, sizeof(unsigned));
	expiryDate.read(is);
	dateOfArrival.read(is);
}
void Batch::write(std::ofstream& os) 
{
	os.write((char*)&productId, sizeof(unsigned));
	os.write((char*)&quantity, sizeof(unsigned));
	expiryDate.write(os);
	dateOfArrival.write(os);
}
bool operator==(Batch const& first, Batch const& second)
{
	return first.productId == second.productId &&
		first.expiryDate == second.expiryDate;
}

void Batch::addQuantity(unsigned _quantity)
{
	quantity += _quantity;
}
void Batch::reduceQuantity(unsigned _quantity)
{
	if (_quantity > quantity)
		std::cerr << "Quantity to reduce must be lower than current quantity" << std::endl;
	quantity -= _quantity;
}
std::ostream& operator<<(std::ostream& of, Batch& batch)
{
	of << "Batch with product id " << batch.productId << " and quantity " << batch.quantity
		<< " and expiry date";
	of << batch.expiryDate;
	return of;
}
