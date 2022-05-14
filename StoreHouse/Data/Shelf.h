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
	DynamicArray<Batch> batches;
	Batch& getFirstBatchOrDefault(int productId, Date const& expiryDate);
public:
	bool searchBatch(Batch const& batch);
	void read(std::ifstream& is);
	void write(std::ofstream& is);
	unsigned getOccupancy()const { return occupancy; }
	unsigned getCapacity()const { return capacity; }
	Shelf(unsigned _capacity);
	Shelf();
	bool AddBatch(Batch const& batch);
	bool ReductionOfProduct(int productId,unsigned quantity);

	//DynamicArray<int> getProductsId();
	unsigned getQuantityOfProduct(int productId);
	bool IsFull();
};
#endif // !SHELF_HPP
