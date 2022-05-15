#ifndef _Section_HPP
#define _Section_HPP
#include "..\Logic\DynamicArray.hpp"
#include "Shelf.h"
//#include "Batch.h"
#include "..\Logic\TextContainer.h"

class Section
{
private:
	DynamicArray<Shelf> shelfs;
	unsigned shelfCapacity ;
public:
	Section();
	DynamicArray<Shelf> getShelfs()const{ return shelfs; }
	int searchBatch(Batch const& batch);
	bool addBatch(Batch const& batch);
	void read(std::ifstream& is);
	void write(std::ofstream& os);
	unsigned getProductQuantitiy(int productId);

	void removeBatchByProductId(int productId);

	Date& searchEarliestExpiryDateOfBatch(int productId);

	void reduceBatch(int productId, unsigned& quantity);

};




#endif // !_Section_HPP

