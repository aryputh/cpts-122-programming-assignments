#pragma once

#include "queueNode.hpp"

#include <iostream>
#include <cstdlib>

class Queue
{
private:
	QueueNode* pHead;
	QueueNode* pTail;

public:
	// Constructor
	Queue(QueueNode* _pHead = nullptr, QueueNode* _pTail = nullptr);

	// Deconstructor
	~Queue();

	// Getter
	QueueNode* getHead();

	// Custom functions
	void enqueue(Data* data);
	Data* dequeue();
	void printQueue();
	bool isEmpty();
};