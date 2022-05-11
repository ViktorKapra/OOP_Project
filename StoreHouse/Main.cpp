// Main.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "TextContainer.h"
#include"UI.h"
#include"WareHouseLogic.h"
#include <charconv>

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
int main()
{
	//TestsearchInFile();
	//UI ui;
	//ui.StartSystem();
	//TestReadingWritingProduct();
//	WarehouseLogic wc;
//	wc.ConfigWareHouse(3, 2);
	//TestTextContainer();
	return 0;
}
