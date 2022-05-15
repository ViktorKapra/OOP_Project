#ifndef _WareHouseLogic_HPP
#define _WareHouseLogic_HPP
#include "..\Data\Product.h"
#include "..\Data\Date.h"
#include "..\Data\Section.h"

class WarehouseLogic 
{
private:
	static const char* CONFIG_FILE_NAME;
	static const char* PRODUCT_FILE_NAME;
	static const int START_SECTION_INDEX = 1;


	unsigned sectionCount;
	unsigned shelfCount;

	void ReadConfigFile();
	void CleanProductFile();
	void createConfigFile(unsigned sectionCount, unsigned shelfCount);
	void CleanSectionFiles(unsigned sectionCount, unsigned shelfCount);
	int searchProductInFile(Product& product);
	void reduceQuantityFromSection(TextContainer const& fileName, int productId, unsigned& quantity);
	
	bool putBatchInSection(Batch& batch, TextContainer const& fileName);
	unsigned getQuantityOfProduct(Product const& product);
	unsigned getProductQuantityOfFile(int productId, TextContainer const& fileName);
	void removeProduct(Product const& product);
	void removeAllBathesWithProductId(int productId);
	void removeProductFromSection(int productId, TextContainer const& fileName);
	void saveChangesInSection(Section& section, TextContainer const& fileName);
	void reduceQuantity(int productId, unsigned quantity);
	Product searchProductByName(char const* productName);
	int addProductInFile(Product& product);
	void addBatch(int productId, unsigned quantity, Date const& expDate);
	int searchLastAddedId();
	DynamicArray<Product> getAllProducts();
public:

	WarehouseLogic();
	void addProduct(Product& product, unsigned quantity, Date const& expDate);
	void ConfigWareHouse(unsigned sectionCount,unsigned shelfCount);
	void reduceProduct(char const* productName, unsigned quantity);
	void getAllProductsAndQuantities();
};


#endif // !_WareHouse_HPP

