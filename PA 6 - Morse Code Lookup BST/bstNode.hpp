#pragma once

#include <string>

class BSTNode
{
private:
	char englishLetter;
	std::string morseCodeString;
	BSTNode* leftPtr;
	BSTNode* rightPtr;

public:
	// Constructor
	BSTNode(char englishLetter = '\0', std::string morseCodeString = "");

	// Getters
	char getEnglishLetter();
	std::string getMorseCodeString();
	BSTNode* getLeftPtr();
	BSTNode* getRightPtr();

	// Setters
	void setEnglishLetter(char letter);
	void setMorseCodeString(const std::string& morseCode);
	void setLeftPtr(BSTNode* left);
	void setRightPtr(BSTNode* right);
};