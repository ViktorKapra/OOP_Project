#include "Shelf.h"
#include "Batch.h"
#include "Product.h"
#include <iostream>
#include "Date.h"

Shelf::Shelf(unsigned _capacity)
{
	if (_capacity == 0)
		std::cerr << "Capacity can  not e 0!" << std::endl;
	capacity = _capacity;
	occupancy = 0;
}

bool Shelf::AddBatch(Batch const& batch)
{
	if (occupancy + batch.getQuantity() <= capacity)
	{
		bool coincidenceBatch = false;
		int coincidenceBatchIndex = -1;
		size_t batchesQuantity = bathes.getSize();
		int i = 0;
		while (!coincidenceBatch && i < batchesQuantity)
		{
			if (bathes[i]==batch)
			{
				coincidenceBatch = true;
				coincidenceBatchIndex = i;
			}
			i++;
		}
		if (coincidenceBatch == true) 
			{ bathes[coincidenceBatchIndex].addQuantity(batch.getQuantity()); }
		else{ bathes.Add(batch); }
		occupancy += batch.getQuantity();
		return true;
	}
	else { return false; }
}

bool Shelf::ReductionOfProduct(int productId, unsigned quantity) 
{
	if (quantity > getQuantityOfProduct(productId))
	{
		size_t batchesQuantity = bathes.getSize();
		DynamicArray<Date> expirationDatesProducts;
		for (int i = 0; i < batchesQuantity; i++)
		{
			if (productId == bathes[i].getProductId())
			{
				expirationDatesProducts.Add(bathes[i].getExpiryDate());
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
				bathes.Remove(expiryBatch);
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
	size_t batchesQuantity = bathes.getSize();
	for (int i = 0; i < batchesQuantity; i++)
	{
		if (productId == bathes[i].getProductId() &&  expiryDate==bathes[i].getExpiryDate())
		{
			result = &bathes[i];
		}
	}
	return *result;
}

unsigned Shelf::getQuantityOfProduct(int productId) 
{
	unsigned quantityOfProduct = 0;
	size_t batchesQuantity = bathes.getSize();
	for (int i = 0; i < batchesQuantity; i++)
	{
		if (productId == bathes[i].getProductId())
		{
			quantityOfProduct+=bathes[i].getQuantity();
		}
	}
	return quantityOfProduct;
}
bool Shelf::IsFull() { return occupancy >= capacity; }
