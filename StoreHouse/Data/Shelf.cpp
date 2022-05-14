#include "Shelf.h"
#include "Batch.h"
#include "Product.h"
#include <iostream>
#include "Date.h"
#include "..\Logic\Constants.h"

Shelf::Shelf()
{
	occupancy = 0;
}
Shelf::Shelf(unsigned _capacity):Shelf()
{
	if (_capacity == 0)
		std::cerr << "Capacity can  not e 0!" << std::endl;
	capacity = _capacity;
}

bool Shelf::AddBatch(Batch const& batch)
{
	if (occupancy + batch.getQuantity() <= capacity)
	{
		bool matchedBatch = false;
		int matchedBatchIndex = Constants::DEFAULT;
		size_t batchesCount = batches.getSize();
		int i = 0;
		while (!matchedBatch && i < batchesCount)
		{
			if (batches[i] == batch)
			{
				matchedBatch = true;
				matchedBatchIndex = i;
			}
			i++;
		}
		if (matchedBatch == true)
		{
			batches[matchedBatchIndex].addQuantity(batch.getQuantity());
		}
		else { batches.Add(batch); }
		occupancy += batch.getQuantity();
		return true;
	}
	else { return false; }
}

bool Shelf::ReductionOfProduct(int productId, unsigned quantity)
{
	if (quantity > getQuantityOfProduct(productId))
	{
		size_t batchesQuantity = batches.getSize();
		DynamicArray<Date> expirationDatesProducts;
		for (int i = 0; i < batchesQuantity; i++)
		{
			if (productId == batches[i].getProductId())
			{
				expirationDatesProducts.Add(batches[i].getExpiryDate());
			}
		}
		sortDates(expirationDatesProducts);
		size_t countOfDates = expirationDatesProducts.getSize();
		int i = 0;
		while (i < countOfDates && quantity>0)
		{
			Batch& expiryBatch = getFirstBatchOrDefault(productId, expirationDatesProducts[i]);
			unsigned expiryBatchQuantity = expiryBatch.getQuantity();
			if (expiryBatchQuantity > quantity)
			{
				expiryBatch.reduceQuantity(quantity);
			}
			else
			{
				quantity -= expiryBatchQuantity;
				batches.Remove(expiryBatch);
			}
			i++;
		}
		return true;

	}
	else { return false; }
}
Batch& Shelf::getFirstBatchOrDefault(int productId, Date const& expiryDate)
{
	Batch* result = nullptr;
	size_t batchesQuantity = batches.getSize();
	for (int i = 0; i < batchesQuantity; i++)
	{
		if (productId == batches[i].getProductId() && expiryDate == batches[i].getExpiryDate())
		{
			result = &batches[i];
		}
	}
	return *result;
}

void Shelf::read(std::ifstream& is)
{
	size_t batchesCount = 0;
	is.read((char*)&batchesCount, sizeof(size_t));
	if (batchesCount != 0)
	{
		is.read((char*)&occupancy, sizeof(occupancy));
		is.read((char*)&capacity, sizeof(capacity));
		for (int i = 0; i < batchesCount; i++)
		{
			Batch batch;
			batch.read(is);
			batches.Add(batch);
		}
	}
}
void Shelf::write(std::ofstream& os)
{
	size_t batchesCount = batches.getSize();
	os.write((char*)&batchesCount, sizeof(size_t));
	if (batchesCount != 0)
	{
		os.write((char*)&occupancy, sizeof(occupancy));
		os.write((char*)&capacity, sizeof(capacity));
		for (int i = 0; i < batchesCount; i++)
		{
			batches[i].write(os);
		}
	}

}
bool Shelf::searchBatch(Batch const& batch)
{
	bool found = false;
	int batchesCount = batches.getSize();
	int i = 0;
	while (!found && i < batchesCount)
	{
		if (batch == batches[i])
			found = true;
		i++;
	}
	return found;
}
unsigned Shelf::getQuantityOfProduct(int productId)
{
	unsigned quantityOfProduct = 0;
	size_t batchesQuantity = batches.getSize();
	for (int i = 0; i < batchesQuantity; i++)
	{
		if (productId == batches[i].getProductId())
		{
			quantityOfProduct += batches[i].getQuantity();
		}
	}
	return quantityOfProduct;
}
bool Shelf::IsFull() { return occupancy >= capacity; }
