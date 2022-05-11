#ifndef _Section_HPP
#define _Section_HPP

#include<DynamicArray.hpp>
#include "Shelf.h"
#include "Batch.h"
#include "TextContainer"

class Section
{
private:
	DynamicArray<Shelf> shelfs;
public:
	Section();
	void addShelf(Shelf const& shelf);
	void addBatch(Batch const& batch);
	void read(TextContainer const& fileName);
	void write(TextContainer const& fileName);
	void getProductQuanitiy(Product const& product);

};




#endif // !_Section_HPP

