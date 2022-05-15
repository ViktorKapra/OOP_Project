//! This class manages user expirience.
//! 
#ifndef _UI_HPP
#define _UI_HPP
#include "../Logic/WareHouseLogic.h"
class UI
{
public:


	void StartSystem();
	void configMenu();
	void devider();
	int chooseFunction();
	int ConfigNewWareHouse();
	int existingWarehouse();
	void wareHouseMenu();
	void addProduct(WarehouseLogic& wc);
	void takeProduct(WarehouseLogic& wc);
};

const int MESSAGE_MAX_LENGHT = 100;
enum ExistFunctions
{
	GetAllProdQuantitiies = 1,
	AddProd = 2,
	TakeProd = 3,
	CheckProd = 4,
	Clearing = 5,
	Close = 6
};

enum ConfigFunctions
{
	NewWareHouse = 1,
	OpenExistingWarehouse = 2,
	Exit = 3
};

#endif // !_UI_HPP

