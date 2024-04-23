#pragma once

#include "BST.hpp"
#include "TransactionNode.hpp"
#include <fstream>

class DataAnalysis
{
// Accessible only to this class
private:
	BST soldTree;
	BST purchasedTree;
	std::ifstream csvStream;

	// Custom functions
	void openStream();
	void closeStream();
	void parseLineOfData(bool tossData, int& _transUnits, std::string& _transData, std::string& _transType);
	void importDataManageBSTs();
	void insertDataInBSTs(int _transUnits, std::string _transData, std::string _transType);
	void displayTrends();

// Accessible to any class
public:
	// Custom functions
	void runAnalysis();
};