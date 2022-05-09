#include "IdGenerator.h"
unsigned IdGenerator::currentId = 1;
IdGenerator::IdGenerator()
{
	currentId++;;
}

int IdGenerator::GetId(){
	return currentId;
}
