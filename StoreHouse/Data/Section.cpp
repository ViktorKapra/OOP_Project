#include"Section.h"
#include "..\Logic\Constants.h"

/// Shelf capacity is set constant to 20 (In next release this must be configured by the user)
Section::Section()
{
	shelfCapacity = 20;
}
int Section::searchBatch(Batch const& batch)
{
	int shelfsCount = shelfs.getSize();
	int foundInShelf = Constants::DEFAULT;
	int i = 0;
	while (foundInShelf == Constants::DEFAULT && i < shelfsCount)
	{
		if (shelfs[i].searchBatch(batch)) { foundInShelf = i; }
		i++;
	}
	return foundInShelf;
}

bool Section::addBatch(Batch const& batch)
{
	bool placed = false;
	int shelfNumber = searchBatch(batch);
	if (shelfNumber != Constants::DEFAULT && shelfs[shelfNumber].AddBatch(batch))
	{
		placed = true;
	}
	else
	{
		int shelfsCount = shelfs.getSize();
		int i = 0;
		do
		{
			if (shelfs[i++].AddBatch(batch)) { placed = true; }
		} while (!placed && i < shelfsCount);
	}
	return placed;
}
void Section::read(std::ifstream& is)
{
	size_t shelfCount = 0;
	is.read((char*)&shelfCount, sizeof(size_t));
	for (int i = 0; i < shelfCount; i++)
	{
		Shelf shelf(shelfCapacity);
		shelf.read(is);
		shelfs.Add(shelf);
	}
}

void Section::write(std::ofstream& os) 
{
	size_t shelfCount = shelfs.getSize();
	os.write((char*)&shelfCount, sizeof(size_t));
	for (int i = 0; i < shelfCount; i++)
	{
		shelfs[i].write(os);
	}
}
unsigned Section::getProductQuantitiy(int productId) 
{
	unsigned quantity = 0;
	unsigned shelfCount = shelfs.getSize();
	for (int i = 0; i < shelfCount; i++)
	{
		quantity += shelfs[i].getQuantityOfProduct(productId);
	}
	return quantity;
}
