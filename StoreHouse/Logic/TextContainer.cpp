#include "TextContainer.h"
#include <cstring>
#include<iostream>
TextContainer::TextContainer()
{
	text = nullptr;
	lenght = 0;
}
TextContainer::TextContainer(char const* _text) :text(nullptr)
{
	setText(_text);
}
TextContainer& TextContainer:: operator=(const TextContainer& textCon)
{
	if (this != &textCon)
	{
		setText(textCon.text);
	}
	return *this;
}
bool TextContainer::operator==(const TextContainer& textCon)
{
	if (strcmp(this->text, textCon.text) == 0)
		return true;
	return false;
}
void TextContainer::setText(char const* _text)
{
	if (text != nullptr)
	{
		delete[] text;
	}
	lenght = strlen(_text) + 1;
	text = new char[lenght];
	strncpy_s(text, lenght, _text, lenght);
	text[lenght - 1] = '\0';

}
TextContainer::TextContainer(const TextContainer& textCon) :TextContainer(textCon.text)
{
}
TextContainer::~TextContainer()
{
	if (text != nullptr)
	{
		delete[] text;
	}
}
int TextContainer::getLenghtOfText() const
{
	return strlen(text);
}
TextContainer TextContainer:: operator+(const TextContainer& textCon)
{

	int conTextLenght = strlen(text) + strlen(textCon.text) + 1;
	char* concatText = new char[conTextLenght];
	strncpy(concatText, text, strlen(text));
	concatText[strlen(text)] = '\0';
	strcat(concatText, textCon.text);
	concatText[conTextLenght] = '\0';

	TextContainer result;
	result.setText(concatText);
	return result;
}

void TextContainer::convertIntToTextContainer(int integer)
{
	char reverseResult[20];
	int i = 0;
	do
	{
		reverseResult[i++] = integer % 10 + '0';

		integer /= 10;
	} while (integer > 0 && i < 20);
	char result[20];
	for (int y = 0; y < i; y++)
	{
		result[y] = reverseResult[i - y - 1];
	}
	result[i] = '\0';
	setText(result);
}

