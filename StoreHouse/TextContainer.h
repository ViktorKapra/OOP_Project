#pragma once

class TextContainer
{
private:
	char* text;
public:
	TextContainer();
	TextContainer(const char* text);
	TextContainer& operator=(const TextContainer& textCon);
	void setText(const char* _text);
	TextContainer(const TextContainer& textCon);
	~TextContainer();
	char const* getText()const { return text; }

};