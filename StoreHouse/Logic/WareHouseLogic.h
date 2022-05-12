#ifndef _WareHouseLogic_HPP
#define _WareHouseLogic_HPP
#include "..\Data\Product.h"
#include "..\Data\Date.h"
#include "..\Data\Batch.h"
class WarehouseLogic 
{
private:
	static const char* CONFIG_FILE_NAME;
	static const char* PRODUCT_FILE_NAME;
	static const int START_SECTION_INDEX = 1;
	static const int DEFAULT = -1;

	unsigned sectionCount;
	unsigned shelfCount;

	void addBatch(int productId, unsigned quantity,Date const& expDate);
	void ReadConfigFile();
	void CleanProductFile();
	void createConfigFile(unsigned sectionCount, unsigned shelfCount);
	void CleanSectionFiles(unsigned sectionCount);
	int searchProductInFile(Product& product);

public:
	void addProduct(Product& product,unsigned quantity,Date const& expDate);
	WarehouseLogic();
	bool putBatchInSection(Batch& batch, TextContainer const& fileName);
	void ConfigWareHouse(unsigned sectionCount,unsigned shelfCount);
	int addProductInFile(Product& product);
	int searchLastAddedId();
	

};


#endif // !_WareHouse_HPP

