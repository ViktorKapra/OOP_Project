#pragma once
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
	unsigned shelfCount = 0;
	is.read((char*)&shelfCount, sizeof(unsigned));
	for (int i = 0; i < shelfCount; i++)
	{
		Shelf shelf(shelfCapacity);
		shelf.read(is);
		shelfs.Add(shelf);
	}
}

void Section::write(std::ofstream& os)
{
	unsigned shelfCount = shelfs.getSize();
	os.write((char*)&shelfCount, sizeof(unsigned)); // unsinged
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

void Section::removeBatchByProductId(int productId)
{
	int shelfsCount = shelfs.getSize();
	for (int i = 0; i < shelfsCount; i++)
	{
		if (shelfs[i].removeBatchByProductId(productId))
			std::cout << "Was removed from shelf " << i << std::endl;
	}
}

Date& Section::searchEarliestExpiryDateOfBatch(int productId)
{
	Date earliestExpiryDate(0, 0, Constants::MAX_YEAR);
	int shelfsCount = shelfs.getSize();
	for (int i = 0; i < shelfsCount; i++)
	{
		Date date = shelfs[i].searchEarliestExpiryDate(productId);
		if (earliestExpiryDate > date)
		{
			earliestExpiryDate = date;
		}
	}
	return earliestExpiryDate;
}
void Section::reduceBatch(int productId, unsigned& quantity)
{
	int shelfCount = shelfs.getSize();
	int i = 0;
	while (quantity > 0 && i < shelfCount)
	{
		if (shelfs[i].ReductionOfProduct(productId, quantity) == true)
		{
			std::cout << "Were removed from shelf " << i << std::endl;
		}
		i++;
	}
}
