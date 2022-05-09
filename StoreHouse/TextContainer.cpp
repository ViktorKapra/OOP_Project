#include "TextContainer.h"
#include <cstring>
TextContainer::TextContainer()
{
	text = nullptr;
	lenght = 0;
}
TextContainer::TextContainer(char const* _text) :TextContainer()
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
void TextContainer::setText( char const* _text)
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
