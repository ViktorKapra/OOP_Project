//! This file contains user test. 
//! Many of them was used for easy configuring of files and debuging.
//! 
#pragma once
#include <iostream>

#include "..\Logic\TextContainer.h"
#include "..\Logic\WareHouseLogic.h"
#include"..\UI\UI.h"
#include "..\Data\Date.h"
#include "..\Data\Product.h"
#include "..\Data\Section.h"


 class Test
{
public:
	Test::Test()
	{
	}
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
	
	void TestAddProduct() ///To use this test you must give it additional acces
	{
		WarehouseLogic wc;
		Product p("Banan", "banana co", "Vkusen");
//		int res = wc.addProductInFile(p);

	}
	void TestSearchLastAdded() ///To use this test you must give it additional acces
	{
		WarehouseLogic wc;
//		std::cout << wc.searchLastAddedId();
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
		wc.addProduct(p, 3, expDate);

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

	void TestGetAllProductsAndQuantities()
	{
		WarehouseLogic wc;
		wc.getAllProductsAndQuantities();
	}
	void TestReadingSectionFile()
	{
		char* fileName = "Section1.bin";
		std::ifstream is;
		is.open("Section1.bin", std::ios::in | std::ios::binary);
		Section section;
		section.read(is);
		is.close();
		DynamicArray<Shelf> shelfs = section.getShelfs();
		std::cout << shelfs[0].getOccupancy() << std::endl;
		std::cout << section.getProductQuantitiy(0);
	}

	void TestReduceProductFunctionallity()
	{
		WarehouseLogic wc;
		wc.reduceProduct("Bira Bolqrka", 2);
	}
	void TryTets()
	{
		//	TestGetAllProductsAndQuantities();

			//TestCurrentDate();
			//TestSearchLastAdded();
			//TestAddProduct();
			//TestsearchInFile();
		//	TestReduceProductFunctionallity();
		//	WarehouseLogic wc;
		//	wc.ConfigWareHouse(3, 3);
		//	TestAddProductFunctionality();
		//	TestReadingSectionFile();
			//TestReadingWritingProduct();
		//	WarehouseLogic wc;
		//	wc.ConfigWareHouse(3, 2);
			//TestTextContainer();
	}
};



