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
	unsigned getProductId()const { return productId; }
	Date getExpiryDate()const { return expiryDate; }
	Date getDateOfArrival()const { return dateOfArrival; }
	unsigned getQuantity()const { return quantity; }
	void read(std::ifstream& is);
	void write(std::ofstream& os);
	friend bool operator==(Batch const& first, Batch const& second);
	friend std::ostream& operator<<(std::ostream& of, Batch & batch);
};
#endif // !Batch_HPP
