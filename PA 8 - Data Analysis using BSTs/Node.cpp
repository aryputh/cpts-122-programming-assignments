#include "Node.hpp"

Node::Node(std::string _nodeData)
{
	nodeData = _nodeData;
	leftPtr = nullptr;
	rightPtr = nullptr;
}

Node::~Node()
{
	
}

// Gets the name of the item
std::string Node::getData()
{
	return nodeData;
}

// Gets the item left pointer
Node*& Node::getLeftPtr()
{
	return leftPtr;
}

// Gets the item right pointer
Node*& Node::getRightPtr()
{
	return rightPtr;
}

// Sets the item name
void Node::setData(std::string _nodeData)
{
	nodeData = _nodeData;
}

// Set the item left pointer
void Node::setLeftPtr(Node*& _leftPtr)
{
	leftPtr = _leftPtr;
}

// Sets the item right pointer
void Node::setRightPtr(Node*& _rightPtr)
{
	rightPtr = _rightPtr;
}