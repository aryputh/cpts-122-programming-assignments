#include "TransactionNode.hpp"

TransactionNode::~TransactionNode()
{
	
}

// Gets the name of the item
std::string TransactionNode::getData()
{
	return nodeData;
}

// Gets the units of the item
int TransactionNode::getUnits()
{
	return units;
}

// Sets the name of the item
void TransactionNode::setData(std::string _nodeData)
{
	nodeData = _nodeData;
}

// Sets the units of the item
void TransactionNode::setUnits(int _units)
{
	units = _units;
}

// Prints the name and units of the item
void TransactionNode::printData()
{
	std::cout << getData() << ": " << getUnits() << " units" << std::endl;
}