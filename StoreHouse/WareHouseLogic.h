#ifndef _WareHouseLogic_HPP
#define _WareHouseLogic_HPP
#include "Product.h"
class WarehouseLogic 
{
private:
	const char* CONFIG_FILE_NAME = "configWR.txt";
	const char* PRODUCT_FILE_NAME = "Products.txt";
	const int START_SECTION_INDEX = 1;
	const int DEFAULT = -1;

	unsigned sectionCount;
	unsigned shelfCount;


	void ReadConfigFile();
	void CleanProductFile();
	void createConfigFile(unsigned sectionCount, unsigned shelfCount);
	void CleanSectionFiles(unsigned sectionCount);
	int searchProductInFile(Product const& product);
public:
	void addProduct(Product const& product,unsigned quantity);
	WarehouseLogic();
	void ConfigWareHouse(unsigned sectionCount,unsigned shelfCount);
	

};


#endif // !_WareHouse_HPP

