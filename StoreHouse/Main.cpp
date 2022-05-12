// Main.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "Logic/TextContainer.h"
#include"Logic/WareHouseLogic.h"
#include"UI/UI.h"
#include "Data/Date.h"
#include "Data/Product.h"

void TestTextContainer()
{
	TextContainer t("awfjawfiwaf");
	TextContainer m = t;
	std::cout << m.getText();
	return;
}
void TestReadingWritingProduct()
{
	Product product;
	std::cin >> product;
	std::cout << product;
}

void TestsearchInFile()
{
	WarehouseLogic wc;
	Product p("Banan", "banana co", "Vkusen");
//	std::cout<<wc.searchProductInFile(p);
}
void TestAddProduct()
{
	WarehouseLogic wc;
	Product p("Banan", "banana co", "Vkusen");
	int res = wc.addProductInFile(p);
}
void TestSearchLastAdded()
{
	WarehouseLogic wc;
	std::cout << wc.searchLastAddedId();
}
void TestCurrentDate()
{
	Date date;
	std::cout << date.getCurrentDate();
}
int main()
{
	TestCurrentDate();
	//TestSearchLastAdded();
	//TestAddProduct();
	//TestsearchInFile();
	//UI ui;
	//ui.StartSystem();
	//TestReadingWritingProduct();
//	WarehouseLogic wc;
//	wc.ConfigWareHouse(3, 2);
	//TestTextContainer();
	return 0;
}
