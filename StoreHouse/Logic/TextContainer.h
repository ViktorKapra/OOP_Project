#pragma once

class TextContainer
{
private:
	char* text;
	int lenght;
public:
	TextContainer();
	TextContainer(const char* text);
	TextContainer& operator=(const TextContainer& textCon);
	friend bool operator==(const TextContainer& textCon, const TextContainer& textCon2);
	void setText(const char* _text);
	TextContainer(const TextContainer& textCon);
	~TextContainer();
	char const* getText()const { return text; }
	int getLenghtOfText()const;
	TextContainer operator+(const TextContainer& textCon);
	void convertIntToTextContainer(int integer);
};