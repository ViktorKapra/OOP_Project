#include "UI.h"
#include "..\Logic\TextContainer.h"
#include <iostream>
#include <iomanip>
#include "..\Logic\WareHouseLogic.h"
#include "..\Data\Product.h"
#include "..\Data\Date.h"


void UI::StartSystem()
{
	int number = 1;
	do {
		configMenu();
		number = chooseFunction();
		switch (number)
		{
		case NewWareHouse:
		{
			ConfigNewWareHouse();
		}break;
		case OpenExistingWarehouse:
		{
			number = existingWarehouse();
		}break;
		case Exit: { }break;
		default:
		{
			std::cerr << "Invalid  number was inserted" << std::endl;
		}break;
		}
	} while (number != Exit);
	return;
}

void UI::configMenu()
{
	devider();
	std::cout << "Welcome to WareHouse system!" << std::endl;
	std::cout << std::setw(10) << "Menu" << std::endl;
	std::cout << "1. Create new warehouse. " << std::endl;
	std::cout << "2. Open last created warehouse." << std::endl;
	std::cout << "3. Exit" << std::endl;
	devider();
}

void UI::devider()
{
	for (int i = 0; i < 40; i++)
		std::cout << "-";
	std::cout << std::endl;
}
int UI::chooseFunction()
{
	int numberFunction = 0;
	std::cout << "Insert number of the commnad: ";
	std::cin >> numberFunction;
	std::cin.ignore();
	return numberFunction;
}
int UI::ConfigNewWareHouse()
{
	unsigned sectionCount = 0;
	unsigned shelfCount = 0;
	std::cout << "Enter number of sections: ";
	std::cin >> sectionCount;
	std::cin.ignore();
	std::cout << " Enter number of shelf of each section: ";
	std::cin >> shelfCount;
	std::cin.ignore();
	if (sectionCount == 0 || shelfCount == 0)
	{
		std::cerr << "Invalid parameters!" << std::endl;

	}
	else
	{
		WarehouseLogic wc;
		wc.ConfigWareHouse(sectionCount, shelfCount);
	}
	return Exit;
}
void UI::wareHouseMenu()
{
	devider();
	std::cout << "WareHouse system" << std::endl;
	std::cout << std::setw(10) << "Menu" << std::endl;
	std::cout << "1. Get all products and quantities. " << std::endl;
	std::cout << "2. Add product." << std::endl;
	std::cout << "3. Take product" << std::endl;
	std::cout << "4. Check product" << std::endl;
	std::cout << "5. Clearing by date." << std::endl;
	std::cout << "6.Close" << std::endl;
	devider();
}

void UI::addProduct(WarehouseLogic & wc)
{
	Product product;
	unsigned quantity;
	char data[MESSAGE_MAX_LENGHT];
	std::cout << "Insert name of the product:";
	std::cin.getline(data, MESSAGE_MAX_LENGHT); //	std::cin.ignore();
	product.setName(data);
	std::cout << "Insert quantity of the product:";
	std::cin >> quantity; 	std::cin.ignore();
	std::cout << "Insert manifcturer of the product:";
	std::cin.getline(data, MESSAGE_MAX_LENGHT); //	std::cin.ignore();
	product.setManifacturer(data);
	std::cout << "Insert comment for the product:";
	std::cin.getline(data, MESSAGE_MAX_LENGHT); //	std::cin.ignore();
	product.setComment(data);
	int day, year, month;
	std::cout << "Insert expiry date for the product"<<std::endl;
	std::cout << "Insert day:";
	std::cin >> day;
	std::cout << "Insert month:";
	std::cin >> month;
	std::cout << "Insert year:";
	std::cin >> year;
	Date expDate(day, month, year);
	wc.addProduct(product, quantity,expDate);

}
void UI::takeProduct(WarehouseLogic& wc)
{
	char productName[MESSAGE_MAX_LENGHT];
	unsigned quantity = 0;
	std::cout << "Insert name of the product:";
	std::cin.getline(productName, MESSAGE_MAX_LENGHT); //	std::cin.ignore();
	std::cout << "Insert quantity of the product:";
	std::cin >> quantity; 	std::cin.ignore();
	wc.reduceProduct(productName, quantity);
}
int UI::existingWarehouse()
{
	WarehouseLogic wc;
	int number = 1;
	do {
		wareHouseMenu();
		number = chooseFunction();
		switch (number)
		{
		case GetAllProdQuantitiies:
		{
			wc.getAllProductsAndQuantities();
		}break;
		case AddProd:
		{
			addProduct(wc);
		}break;
		case TakeProd:
		{
			takeProduct(wc);
		}break;
		case CheckProd:
		{

		}break;
		case Clearing:
		{

		}break;
		case Close:
		{

		}break;
		default:
		{
			std::cerr << "Invalid  number was inserted" << std::endl;
		}break;
		}
	} while (number != Close);
	return number;

}


