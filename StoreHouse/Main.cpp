// Main.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "TextContainer.h"

void TestTextContainer()
{
	TextContainer t("awfjawfiwaf");
	TextContainer m = t;
	std::cout << m.getText();
	return;
}

int main()
{

	//TestTextContainer();
	return 0;
}
