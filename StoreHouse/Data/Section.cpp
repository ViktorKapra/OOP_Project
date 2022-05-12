#include"Section.h"

/// Shelf capacity is set constant to 20 (In next release this must be configured by the user)
Section::Section()
{ 
	shelfCapacity = 20;
}
void Section::addBatch(Batch const& batch)
{
	//int shelfNumber=searchBatch(batch);
}
void Section::read(std::ifstream& is){}
void Section::write(std::ofstream& os){}
void Section::getProductQuanitiy(Product const& product){}
