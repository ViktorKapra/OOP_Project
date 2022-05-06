#include "TextContainer.h"
#include <cstring>
TextContainer::TextContainer()
{
	text = nullptr;
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
	size_t sizeOfText = strlen(_text) + 1;
	text = new char[sizeOfText];
	strncpy_s(text, sizeOfText, _text, sizeOfText);
	text[sizeOfText - 1] = '\0';
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