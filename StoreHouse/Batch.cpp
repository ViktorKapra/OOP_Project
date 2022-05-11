#include"Batch.h"
#include <iostream>

Batch::Batch()
{ }
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
	is.read((char*)productId, sizeof(unsigned));
	is.read((char*)quantity, sizeof(unsigned));
	expiryDate.read(is);
	dateOfArrival.read(is);
}
void Batch::write(std::ofstream& os) const
{
	os.write((const char*)productId, sizeof(unsigned));
	os.write((const char*)quantity, sizeof(unsigned));
	expiryDate.write(os);
	dateOfArrival.write(os);
}
bool Batch::operator==(Batch const& batch)
{
	return this->productId == batch.productId &&
		this->dateOfArrival == batch.dateOfArrival &&
		this->expiryDate == batch.expiryDate;
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
