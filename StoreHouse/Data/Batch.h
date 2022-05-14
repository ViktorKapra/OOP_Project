#ifndef Batch_HPP
#define Batch_HPP


#include "Date.h"
#include <fstream>
class Batch
{
private:
	unsigned productId;
	Date expiryDate;
	Date dateOfArrival;
	unsigned quantity;
public:
	Batch();
	Batch(unsigned _productId, Date _expiryDate, Date _dateOfArival, unsigned _quantity);
	void reduceQuantity(unsigned _quantity);
	void addQuantity(unsigned _quantity);
	bool operator==(Batch const&  batch)const;
	unsigned getProductId()const { return productId; }
	Date getExpiryDate()const { return expiryDate; }
	Date getDateOfArrival()const { return dateOfArrival; }
	unsigned getQuantity()const { return quantity; }
	void read(std::ifstream& is);
	void write(std::ofstream& os)const;
};
#endif // !Batch_HPP
