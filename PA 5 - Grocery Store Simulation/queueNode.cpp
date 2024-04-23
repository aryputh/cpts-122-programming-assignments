#include "queueNode.hpp"

/*
*	Description: This is the constructor for the class. Default values are assigned in the prototype.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: An object is created with the values (or default values) that you supplied.
*/
QueueNode::QueueNode(Data* _pData, QueueNode* _pNext)
{
	this->pData = _pData;
	this->pNext = _pNext;
}

/*
*	Description: This is the deconstructor for the class.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The object has been destroyed.
*/
QueueNode::~QueueNode()
{
	delete this->pData;
}

/*
*	Description: This is the getter for the class.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The data pointer has been returned.
*/
Data* QueueNode::getData()
{
	return this->pData;
}

/*
*	Description: This is the getter for the class.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The next pointer has been returned.
*/
QueueNode* QueueNode::getNext()
{
	return this->pNext;
}

/*
*	Description: This is the setter for the class.
*	Date: 3/4/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The data has been updated.
*/
void QueueNode::setData(Data* newData)
{
	this->pData = newData;
}

/*
*	Description: This is the setter for the class.
*	Date: 3/4/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The next pointer has been updated.
*/
void QueueNode::setNext(QueueNode* newNext)
{
	this->pNext = newNext;
}
