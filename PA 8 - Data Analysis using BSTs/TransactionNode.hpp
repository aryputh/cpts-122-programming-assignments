#pragma once

#include "Node.hpp"
#include <iostream>

class TransactionNode : public Node
{
// Accessible only to this class
private:
	int units;

// Accessible to any class
public:
	// Constructor and destructor
	TransactionNode(std::string _nodeData = "N/A", int _units = 0) : Node(_nodeData)
	{
		units = _units;
	};
	~TransactionNode();

	// Accessors
	std::string getData();
	int getUnits();

	// Mutators
	void setData(std::string _nodeData);
	void setUnits(int _units);

	// Custom functions
	void printData() override;
};