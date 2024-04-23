#include "queue.hpp"
#include "data.hpp"

/*
*	Description: This is the constructor for the class. Default values are assigned in the prototype.
*	Date: 3/4/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: An object is created with the values (or default values) that you supplied.
*/
Queue::Queue(QueueNode* _pHead, QueueNode* _pTail)
{
	this->pHead = _pHead;
	this->pTail = _pTail;
}

/*
*	Description: This is the deconstructor for the class.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The object has been destroyed, with each node being dequeued.
*/
Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

QueueNode* Queue::getHead()
{
	return this->pHead;
}

/*
*	Description: Adds a data node to the queue.
*	Date: 3/4/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: A new piece of data has been added to the queue.
*/
void Queue::enqueue(Data* data)
{
	// Create a copy of the Data object
	QueueNode* newNode = new QueueNode(data, nullptr);

	// Detects if the queue is empty and acts accordingly
	if (isEmpty())
	{
		this->pHead = newNode;
		this->pTail = newNode;
	}
	else
	{
		this->pTail->setNext(newNode);
		this->pTail = newNode;
	}
}

/*
*	Description: Removes a data node from the queue.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: An old piece of data has been removed from the queue.
*/
Data* Queue::dequeue()
{
	if (isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
		return nullptr;
	}
	
	QueueNode* temp = this->pHead;
	//Data* dequeuedData = temp->getData();
	//Data* dequeuedData = new Data(temp->getData()->getCustomerNumber(), temp->getData()->getServiceTime(), temp->getData()->getTotalTime());
	Data* dequeuedData = new Data(*temp->getData());

	this->pHead = this->pHead->getNext();

	if (this->pHead == nullptr)
	{
		this->pTail = nullptr;
	}

	delete temp;

	return dequeuedData;
}

/*
*	Description: Creates a new queue, dequeues nodes, prints out each node, and enqueues them back.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: The entire queue has been printed out.
*/
void Queue::printQueue()
{
	// Handle queue being empty
	if (this->isEmpty())
	{
		std::cout << "Queue is empty." << std::endl;

		return;
	}

	// Create a temp queue to temporarily store dequeued nodes
	Queue tempQueue;

	// Dequeue each node from the original list, print it, and enqueue it to the new list
	while (!this->isEmpty())
	{
		Data* currentData = this->dequeue();

		std::cout << "Customer Number: " << currentData->getCustomerNumber()
			<< " Service Time: " << currentData->getServiceTime()
			<< " Total Time: " << currentData->getTotalTime() << std::endl;

		tempQueue.enqueue(currentData);
	}

	// Dequeue from the new list back to the original list
	while (!tempQueue.isEmpty())
	{
		this->enqueue(tempQueue.dequeue());
	}
}

/*
*	Description: Returns if the list is empty or not.
*	Date: 3/4/2024
*
*	Preconditions: None.
*	Postconditions: Returns if the list is empty or is not.
*/
bool Queue::isEmpty()
{
	return this->pHead == nullptr;
}
