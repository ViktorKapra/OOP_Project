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
	void addBatch(Batch const& batch);
	void read(std::ifstream& is);
	void write(std::ofstream& os);
	void getProductQuanitiy(Product const& product);

};




#endif // !_Section_HPP

