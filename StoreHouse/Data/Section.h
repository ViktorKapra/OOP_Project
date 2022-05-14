#ifndef _Section_HPP
#define _Section_HPP

#include "..\Logic\DynamicArray.hpp"
#include "Shelf.h"
#include "Batch.h"
#include "..\Logic\TextContainer.h"

class Section
{
private:
	DynamicArray<Shelf> shelfs;
	unsigned shelfCapacity ;
public:
	Section();
	int searchBatch(Batch const& batch);
	bool addBatch(Batch const& batch);
	void read(std::ifstream& is);
	void write(std::ofstream& os);
	unsigned getProductQuantitiy(int productId);

};




#endif // !_Section_HPP

