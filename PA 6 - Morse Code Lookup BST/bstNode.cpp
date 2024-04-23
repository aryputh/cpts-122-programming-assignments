#include "bstNode.hpp"

BSTNode::BSTNode(char englishLetter, std::string morseCodeString)
{
	this->englishLetter = englishLetter;
	this->morseCodeString = morseCodeString;
	leftPtr = nullptr;
	rightPtr = nullptr;
}

char BSTNode::getEnglishLetter()
{
    return englishLetter;
}

std::string BSTNode::getMorseCodeString()
{
    return morseCodeString;
}

BSTNode* BSTNode::getLeftPtr()
{
    return leftPtr;
}

BSTNode* BSTNode::getRightPtr()
{
    return rightPtr;
}

void BSTNode::setEnglishLetter(char letter)
{
    englishLetter = letter;
}

void BSTNode::setMorseCodeString(const std::string& morseCode)
{
    morseCodeString = morseCode;
}

void BSTNode::setLeftPtr(BSTNode* left)
{
    leftPtr = left;
}

void BSTNode::setRightPtr(BSTNode* right)
{
    rightPtr = right;
}