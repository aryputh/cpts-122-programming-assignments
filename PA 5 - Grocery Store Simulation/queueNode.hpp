#pragma once

#include "data.hpp"

#include <iostream>
#include <cstdlib>

class QueueNode
{
private:
	Data* pData;
	QueueNode* pNext;

public:
	// Constructor
	QueueNode(Data* _pData = nullptr, QueueNode* _pNext = nullptr);

	// Deconstructor
	~QueueNode();

	// Getters
	Data* getData();
	QueueNode* getNext();

	// Setters
	void setData(Data* newData);
	void setNext(QueueNode* newNext);
};