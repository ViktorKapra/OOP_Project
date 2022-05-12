#include "WareHouseLogic.h"
#include <fstream>
#include "TextContainer.h"
#include <iostream>
#include <cstring>
#include"..\Data\Date.h"
#include "..\Data\Batch.h"
#include "..\Data\Section.h"

char const* WarehouseLogic::CONFIG_FILE_NAME = "configWR.txt";
char const* WarehouseLogic::PRODUCT_FILE_NAME = "Products.txt";

void WarehouseLogic::addProduct(Product& product, unsigned quantity, Date const& expDate)
{
		int productId = searchProductInFile(product);
		if (productId == DEFAULT)
		{
			productId = addProductInFile(product);
		}
		addBatch(productId, quantity,expDate);
}
bool WarehouseLogic::putBatchInSection(Batch& batch,TextContainer const& fileName)
{
	std::ifstream os;
	os.open(fileName.getText(), std::ios::in | std::ios::binary);
	Section section;
	section.read(os);

	os.close();
}
void WarehouseLogic::addBatch(int productId, unsigned quantity, Date const& expDate)
{
	Batch batch(productId, expDate, Date().getCurrentDate(), quantity);
	bool success = false;
	TextContainer fileName("Section");
	TextContainer ending(".bin");
	for (int i = START_SECTION_INDEX; i <= sectionCount; i++)
	{
		TextContainer index;
		index.convertIntToTextContainer(i);
		TextContainer fullFileName = fileName + index + ending;
		success = putBatchInSection(batch, fullFileName);
	}

	
}
int WarehouseLogic::addProductInFile(Product& product)
{
	int productId=searchLastAddedId()+1;
	product.setId(productId);
	std::ofstream os;
	os.open(PRODUCT_FILE_NAME, std::ios::app);
	os<< product;
	return productId;
}
int WarehouseLogic::searchLastAddedId()
{
	int productId = DEFAULT;
	std::ifstream is;
	is.open(PRODUCT_FILE_NAME, std::ios::in);
	Product currentProduct;
	while (is)
	{
		is >> currentProduct;
	//	std::cout << currentProduct;
		if (is)
		{ productId = currentProduct.getId();}
	}
	is.close();
	return productId;

}
int WarehouseLogic::searchProductInFile(Product & product)
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
	const int  maxLenghtMessage = 100;
	char ignore[maxLenghtMessage];
	std::ifstream is;
	is.open(CONFIG_FILE_NAME, std::ios::in);
	if (is)
	{
		is.getline(ignore, maxLenghtMessage);
		is.getline(ignore, maxLenghtMessage);
		is >> sectionCount;
		is.getline(ignore, maxLenghtMessage);
		is.getline(ignore, maxLenghtMessage);
		is >> shelfCount;
		//std::cout << sectionCount << " " << shelfCount << std::endl;
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
