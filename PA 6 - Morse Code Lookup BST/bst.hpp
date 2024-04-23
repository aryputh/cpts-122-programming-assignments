#pragma once

#include "bstNode.hpp"
#include <iostream>
#include <fstream>

class BST
{
private:
	BSTNode* rootPtr;
	std::ifstream inputFile;

	// Private helper functions for the public ones
	void insert(BSTNode* newNode, BSTNode* nodePtr);
	void print(BSTNode* nodePtr);
	BSTNode* search(char character, BSTNode* nodePtr);
	void destroyTree(BSTNode* nodePtr);

public:
	// Constructor
	BST();

	// Destructor
	~BST();

	// Public member functions
	void insert(char character, const std::string& morse);
	void print();
	std::string search(char character);
};