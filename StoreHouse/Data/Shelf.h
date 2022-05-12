#ifndef SHELF_HPP
#define SHELF_HPP


#include "..\Logic\DynamicArray.hpp"
#include "Batch.h"
#include "Product.h"
class Shelf
{
private:
	unsigned capacity;
	unsigned occupancy;
	DynamicArray<Batch> bathes;
	Batch& getFirstBatchOrDefault(int productId, Date const& expiryDate);
public:
	unsigned getOccupancy()const { return occupancy; }
	unsigned getCapacity()const { return capacity; }
	Shelf(unsigned _capacity);
	bool AddBatch(Batch const& batch);
	bool ReductionOfProduct(int productId,unsigned quantity);

	//DynamicArray<int> getProductsId();
	unsigned getQuantityOfProduct(int productId);
	bool IsFull();
};
#endif // !SHELF_HPP
