#pragma once
#include "WareHouseLogic.h"
#include <fstream>
#include "TextContainer.h"
#include <iostream>
#include <cstring>
#include "Constants.h"

char const* WarehouseLogic::CONFIG_FILE_NAME = "configWR.txt";
char const* WarehouseLogic::PRODUCT_FILE_NAME = "Products.txt";

void WarehouseLogic::reduceQuantityFromSection(TextContainer const& fileName,int productId, unsigned& quantity) 
{
	std::ifstream is;
	is.open(fileName.getText(), std::ios::in | std::ios::binary);
	Section section;
	Date earliestExpiryDate;
	if (is.is_open())
	{
		section.read(is);
		section.reduceBatch(productId, quantity);
		is.close();
		saveChangesInSection(section, fileName);
	}
	else
	{
		std::cerr << "File was not found!" << std::endl;
	}

}
void WarehouseLogic::addProduct(Product& product, unsigned quantity, Date const& expDate)
{
	int productId = searchProductInFile(product);
	if (productId == Constants::DEFAULT)
	{
		productId = addProductInFile(product);
	}
	addBatch(productId, quantity, expDate);
}
bool WarehouseLogic::putBatchInSection(Batch& batch, TextContainer const& fileName)
{
	std::ifstream is;
	is.open(fileName.getText(), std::ios::in | std::ios::binary);
	Section section;
	section.read(is);
	bool result = section.addBatch(batch);
	is.close();
	std::cout << result << std::endl;
	saveChangesInSection(section, fileName);
	return result;
}
void WarehouseLogic::addBatch(int productId, unsigned quantity, Date const& expDate)
{
	Batch batch(productId, expDate, Date().getCurrentDate(), quantity);
	bool success = false;
	TextContainer fileName("Section");
	TextContainer ending(".bin");
	int i = START_SECTION_INDEX;
	do
	{
		TextContainer index;
		index.convertIntToTextContainer(i);
		TextContainer fullFileName = fileName + index + ending;
		success = putBatchInSection(batch, fullFileName);
		i++;
	} while (i <= sectionCount && !success);
}
int WarehouseLogic::addProductInFile(Product& product)
{
	int productId = searchLastAddedId() + 1;
	product.setId(productId);
	std::ofstream os;
	os.open(PRODUCT_FILE_NAME, std::ios::app);
	os << product;
	return productId;
}
int WarehouseLogic::searchLastAddedId()
{
	int productId = Constants::DEFAULT;
	std::ifstream is;
	is.open(PRODUCT_FILE_NAME, std::ios::in);
	Product currentProduct;
	while (is)
	{
		is >> currentProduct;
		//	std::cout << currentProduct;
		if (is)
		{
			productId = currentProduct.getId();
		}
	}
	is.close();
	return productId;

}
int WarehouseLogic::searchProductInFile(Product& product)
{
	int result = Constants::DEFAULT;
	Product currentProduct;
	std::ifstream is;
	is.open(PRODUCT_FILE_NAME, std::ios::in);
	while (is && result == Constants::DEFAULT)
	{
		is >> currentProduct;
		if (strcmp(currentProduct.getName(), product.getName()) == 0)
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
		std::cerr << "Config file is missing!" << std::endl;
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
void WarehouseLogic::CleanSectionFiles(unsigned sectionCount, unsigned shelfCount)
{
	TextContainer fileName("Section");
	TextContainer ending(".bin");
	std::ofstream os;
	for (int i = START_SECTION_INDEX; i <= sectionCount; i++)
	{
		TextContainer index;
		index.convertIntToTextContainer(i);
		os.open((fileName + index + ending).getText(), std::ios::out | std::ios::binary | std::ios::trunc);
		//os.write((char*)(&sectionCount),sizeof(unsigned));
		os.write((char*)(&shelfCount), sizeof(unsigned));
		for (int i = 0; i < shelfCount; i++)
		{
			size_t batchCount = 0;
			os.write((char*)(&batchCount), sizeof(size_t));
		}
		os.close();
		//os.open()
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
	createConfigFile(sectionCount, shelfCount);
	CleanSectionFiles(sectionCount, shelfCount);
	CleanProductFile();
}

DynamicArray<Product> WarehouseLogic::getAllProducts()
{
	DynamicArray<Product> products;
	std::ifstream is;
	is.open(PRODUCT_FILE_NAME, std::ios::in);
	Product currentProduct;
	while (!is.eof())
	{
		is >> currentProduct;
		if (is)
			products.Add(currentProduct);
	}
	is.close();
	return products;
}

void WarehouseLogic::getAllProductsAndQuantities()
{
	DynamicArray<Product> products = getAllProducts();
	unsigned productCount = products.getSize();
	for (int i = 0; i < productCount; i++)
	{
		std::cout << products[i];
		unsigned currentProductQuantity = getQuantityOfProduct(products[i]);
		std::cout << "Quantity :" << currentProductQuantity << std::endl;
	}

}

unsigned WarehouseLogic::getQuantityOfProduct(Product const& product)
{
	unsigned result = 0;
	TextContainer fileName("Section");
	TextContainer ending(".bin");
	int i = START_SECTION_INDEX;
	do
	{
		TextContainer index;
		index.convertIntToTextContainer(i);
		TextContainer fullFileName = fileName + index + ending;
		result += getProductQuantityOfFile(product.getId(), fullFileName);
		i++;
	} while (i <= sectionCount);
	return result;
}

unsigned WarehouseLogic::getProductQuantityOfFile(int productId, TextContainer const& fileName)
{
	int result = 0;
	std::ifstream is;
	is.open(fileName.getText(), std::ios::in | std::ios::binary);
	Section section;
	section.read(is);
	result += section.getProductQuantitiy(productId);
	return result;
}
void WarehouseLogic::removeProduct(Product const& product)
{
	DynamicArray<Product> products = getAllProducts();
	products.Remove(product);
	CleanProductFile();
	unsigned productsCount = products.getSize();
	for (int i = 0; i < productsCount; i++)
	{
		addProductInFile(products[i]);
	}
	removeAllBathesWithProductId(product.getId());
}
void WarehouseLogic::removeAllBathesWithProductId(int productId)
{
	TextContainer fileName("Section");
	TextContainer ending(".bin");
	int i = START_SECTION_INDEX;
	for (int i = START_SECTION_INDEX; i < sectionCount; i++)
	{
		TextContainer index;
		index.convertIntToTextContainer(i);
		TextContainer fullFileName = fileName + index + ending;
		std::cout << "Removed bathes from section " << index.getText() << std::endl;
		removeProductFromSection(productId, fullFileName);
	}
}
void WarehouseLogic::removeProductFromSection(int productId, TextContainer const& fileName)
{
	std::ifstream is;
	is.open(fileName.getText(), std::ios::in | std::ios::binary);
	Section section;
	if (is.is_open())
	{
		section.read(is);
		section.removeBatchByProductId(productId);
		is.close();
		saveChangesInSection(section, fileName);

	}
	else
	{
		std::cerr << "File was not found!" << std::endl;
	}
}
void WarehouseLogic::saveChangesInSection(Section& section, TextContainer const& fileName)
{
	std::ofstream os;
	os.open(fileName.getText(), std::ios::out | std::ios::binary | std::ios::trunc);
	if (os.is_open())
	{
		section.write(os);
		os.close();
	}
}
void WarehouseLogic::reduceQuantity(int productId, unsigned quantity)
{
	TextContainer fileName("Section");
	TextContainer ending(".bin");
	int i = START_SECTION_INDEX;
	do
	{
		TextContainer index;
		index.convertIntToTextContainer(i);
		TextContainer fullFileName = fileName + index + ending;
		std::cout << "From section " << i << std::endl;
		reduceQuantityFromSection(fullFileName, productId, quantity);
		i++;
	} while (i <= sectionCount && quantity > 0);
}
void WarehouseLogic::reduceProduct(char const* productName, unsigned quantity)
{
	Product product = searchProductByName(productName);
	if (product.getId() == Constants::DEFAULT)
	{
		std::cerr << "Product with name " << productName << " was not found!" << std::endl;
	}
	else
	{
		unsigned productQuantity = getQuantityOfProduct(product);
		if (quantity >= productQuantity)
		{
			if (quantity > productQuantity)
			{
				std::cout << "There is no enough quantity of that product!" << std::endl;
				std::cout << "There is " << productQuantity << " left of product with name " << productName << std::endl;
				char answer;
				std::cout << "Do you want to remove all stock? [Y\\N]: " << std::endl;
				std::cin >> answer;
				if (answer == 'N') { return; }
			}
			removeProduct(product);
		}
		else
		{
			reduceQuantity(product.getId(), quantity);
		}

	}
}

Product WarehouseLogic::searchProductByName(char const* productName)
{
	std::ifstream is;
	is.open(PRODUCT_FILE_NAME, std::ios::in);
	Product currentProduct;
	while (!is.eof())
	{
		is >> currentProduct;
		if (is)
		{
			if (strcmp(productName, currentProduct.getName()) == 0)
				return currentProduct;
		}
	}
	is.close();
	Product defaultProduct;
	defaultProduct.setId(Constants::DEFAULT);
	return defaultProduct;

}
