#pragma once

#include <string>

class Node
{
// Only accessible to this and derived classes
protected:
	std::string nodeData;
	Node* leftPtr;
	Node* rightPtr;

// Accessible to any class
public:
	// Constructor and destructor
	Node(std::string _nodeData = "N/A");
	virtual ~Node();

	// Accessors
	std::string getData();
	Node*& getLeftPtr();
	Node*& getRightPtr();

	// Mutators
	void setData(std::string _nodeData);
	void setLeftPtr(Node*& _leftPtr);
	void setRightPtr(Node*& _rightPtr);

	// Custom functions
	virtual void printData() = 0;
};