#include "WareHouseLogic.h"
#include <fstream>
#include "UI.h"
#include "TextContainer.h"
#include <iostream>
#include "DynamicArray.hpp"
#include <cstring>

void WarehouseLogic::addProduct(Product const& product, unsigned quantity)
{
		int productId = searchProductInFile(product);
		if (productId == DEFAULT)
		{
//			productId = addProductInFile(product);
		}
	//	addBatch(productId, quantity);

}
int WarehouseLogic::searchProductInFile(Product const& product)
{
	int result = DEFAULT;
	Product currentProduct;
	std::ifstream is;
	is.open(PRODUCT_FILE_NAME, std::ios::in);
	while (is && result==DEFAULT)
	{
		is >> currentProduct;
		if (strcmp(currentProduct.getName(), product.getName())==0)
		{
			result = currentProduct.getId();
		}
	}

	return result;
}

WarehouseLogic::WarehouseLogic()
{
	ReadConfigFile();
}
void WarehouseLogic::ReadConfigFile()
{
	char ignore[MESSAGE_MAX_LENGHT];
	std::ifstream is;
	is.open(CONFIG_FILE_NAME, std::ios::in);
	if (is)
	{
		is.getline(ignore,MESSAGE_MAX_LENGHT);
		is.getline(ignore, MESSAGE_MAX_LENGHT);
		is >> sectionCount;
		is.getline(ignore, MESSAGE_MAX_LENGHT);
		is.getline(ignore, MESSAGE_MAX_LENGHT);
		is >> shelfCount;
		std::cout << sectionCount << " " << shelfCount << std::endl;
		is.close();
	}
	else
	{
		std::cerr << "Config file is missing!"<<std::endl;
	}
}
void WarehouseLogic::createConfigFile(unsigned sectionCount, unsigned shelfCount)
{
	std::ofstream os;
	os.open(CONFIG_FILE_NAME, std::ios::out | std::ios::trunc);
	if (os)
	{
		os << "Warehouse configurations:" << std::endl;
		os << "Sections:" << "\n";
		os << sectionCount;
		os << "\n";
		os << "Shelfs of section:" << "\n";
		os << shelfCount;
		os << "\n";
		os.close();
	}
}
void WarehouseLogic::CleanSectionFiles(unsigned sectionCount)
{
	TextContainer fileName("Section");
	TextContainer ending(".bin");
	std::ifstream is;
	for (int i = START_SECTION_INDEX; i <= sectionCount; i++)
	{
		TextContainer index;
		index.convertIntToTextContainer(i);
		is.open((fileName + index + ending).getText(), std::ios::out | std::ios::binary | std::ios::trunc);
		is.close();
	}
}
void WarehouseLogic::CleanProductFile()
{
	std::ofstream os;
	os.open(PRODUCT_FILE_NAME, std::ios::out | std::ios::trunc);
	os.close();
}
void WarehouseLogic::ConfigWareHouse(unsigned sectionCount, unsigned shelfCount)
{
	createConfigFile(sectionCount,shelfCount);
	CleanSectionFiles(sectionCount);
	CleanProductFile();
}
