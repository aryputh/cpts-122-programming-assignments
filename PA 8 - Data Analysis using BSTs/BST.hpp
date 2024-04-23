#pragma once

#include "Node.hpp"
#include "TransactionNode.hpp"
#include <iostream>

class BST
{
// Accessible only to this class
private:
	Node* rootPtr;

	// Custom functions
	void destroyTree(Node* _nodePtr);
	void insert(Node*& _nodePtr, std::string& _nodeData, int& _units);
	void inOrderTraversal(Node* _nodePtr);
	TransactionNode& smallest(Node* _nodePtr);
	TransactionNode& largest(Node* _nodePtr);

// Accessible to any class
public:
	// Constructor and destructor
	BST();
	~BST();

	// Accessors
	Node* getRootPtr();

	// Mutators
	void setRootPtr(Node* _rootPtr);

	// Custom functions
	void insertNode(std::string _nodeData, int _units);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();
};