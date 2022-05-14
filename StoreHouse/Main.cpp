// Main.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "Logic/TextContainer.h"
#include"Logic/WareHouseLogic.h"
#include"UI/UI.h"
#include "Data/Date.h"
#include "Data/Product.h"
#include "Data/Section.h"

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
void TestAddProductFunctionality()
{
	Product p("Bira Bolqrka", "Bolqrka OOD", "Tarnovska bira");
	int quantity = 3;
	Date expDate(3, 9, 2022);
	WarehouseLogic wc;
	wc.addProduct(p, 3,expDate);

	Product p1("Bira Pirinsko", "Pirinsko OOD", "Uvajavana bira");
	Date expDate1(10, 10, 2022);
	wc.addProduct(p1, 5, expDate1);

	Product p2("Bira Shumensko", "Shumensko OOD", "Shumenska bira");
	Date expDate2(30, 9, 2022);
	wc.addProduct(p2, 2, expDate2);
	
//	std::ifstream is;
//	is.open("Section1.bin", std::ios::in | std::ios::binary);
//	Section section;
//	section.read(is);
//	is.close();

}

int main()
{
	//TestCurrentDate();
	//TestSearchLastAdded();
	//TestAddProduct();
	//TestsearchInFile();
	//UI ui;
	//ui.StartSystem();
	TestAddProductFunctionality();
	//TestReadingWritingProduct();
//	WarehouseLogic wc;
//	wc.ConfigWareHouse(3, 2);
	//TestTextContainer();
	return 0;
}


/*
2
2
Beer
3
Bolqrka
Koles
19
6
2022


*/
