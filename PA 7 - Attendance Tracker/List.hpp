#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <ctime>
#include "Data.hpp"
#include "Node.hpp"

template <class T>
class List
{
private:
	Node<T>* headPtr;
	void destroyListHelper(Node<T>* _nodePtr);

public:
	List(Node<T>* _headPtr = nullptr);
	List(List<T>* _list);
	~List();
	Node<T>* getHeadPtr() const;
	void insertAtFront(Data* _newData);
	Data deleteAtFront();
	void destroyList();
	void markAbsences();
	void printRecentAbsences(std::ofstream& absenceReport1);
	void printListbyAbsences(std::ofstream& absenceReport2, int absenceThreshold);
	void printListIntoFile(std::fstream& master);
	List<T>* operator= (List<T>* _rhs);
};

template<class T>
void List<T>::destroyListHelper(Node<T>* _nodePtr)
{
	// While there are nodes still left
	if (_nodePtr != nullptr)
	{
		// Recursivly call the function again
		destroyListHelper(_nodePtr->getNextPtr());

		delete _nodePtr;
	}
}

template<class T>
List<T>::List(Node<T>* _headPtr)
{
	headPtr = _headPtr;
}

template<class T>
List<T>::List(List<T>* _list)
{
	// Start with beginning
	if (_list.headPtr == nullptr)
	{
		headPtr = nullptr;
	}
	else
	{
		// Start with the first newNode
		Node* newNode = new Node(_list.headPtr->getData());
		headPtr = newNode;

		// Copy the rest of the newNodes
		Node* currentNode = _list.headPtr->getNextPtr();

		while (currentNode != nullptr)
		{
			// Copy the newNode
			Node* newNode = new Node(currentNode->getData());

			// Add the newNode to the end of the list
			newNode->setNextPtr(newNode);

			// Record the last newNode in the list
			newNode = newNode;
		}
	}
}

template<class T>
List<T>::~List()
{
	destroyList();
}

template<class T>
Node<T>* List<T>::getHeadPtr() const
{
	return headPtr;
}

template<class T>
void List<T>::insertAtFront(Data* _newData)
{
	// Create a new node
	Node<T>* newNode = new Node<Data>(*_newData);

	// Ensure a new node was created
	if (newNode != nullptr)
	{
		// newNode is pointing to a Node object
		newNode->setNextPtr(headPtr);
		headPtr = newNode;
	}
}

template<class T>
Data List<T>::deleteAtFront()
{
	// Declare required variables
	Data data;

	// Delete the first node and update the head pointer
	Node<T>* node = headPtr;
	data = node->getData();
	headPtr = node->getNextPtr();

	delete node;

	return data;
}

template<class T>
void List<T>::destroyList()
{
	destroyListHelper(headPtr);
}

template<class T>
void List<T>::markAbsences()
{
	Node<T>* node = headPtr;
	Data* nodeData;
	char absenceDecision = '-';
	std::string absenceDate = "";

	// While there are nodes still left
	while (node != nullptr)
	{
		nodeData = node->getData();

		// Prompt and get input from user on whether the student is present or not
		std::cout << "Is " << nodeData->getName() << " absent? (Y/N)" << std::endl;

		do
		{
			std::cin >> absenceDecision;
		}
		while (!(absenceDecision == 'Y' || absenceDecision == 'N'
			|| absenceDecision == 'y' || absenceDecision == 'n'));

		// Mark user as absent, if they are
		if (absenceDecision == 'Y' || absenceDecision == 'y')
		{
			// Get time now
			std::time_t now = std::time(0);
			struct tm* timestamp = localtime(&now);

			// Create the date in the form mm/dd/yyyy
			absenceDate = std::to_string(timestamp->tm_mon + 1) + "/" + std::to_string(timestamp->tm_mday) + "/"
				+ std::to_string(timestamp->tm_year + 1900);

			// Add the absence date to the student and increase number of absences
			nodeData->getDatesOfAbsences()->push(absenceDate);
			nodeData->setNumberAbsences(nodeData->getNumberAbsences() + 1);
		}

		// Reset absence decision
		absenceDecision = '-';

		// Go to next node
		node = node->getNextPtr();
	}
}

template<class T>
void List<T>::printRecentAbsences(std::ofstream& absenceReport1)
{
	Node<T>* node = headPtr;
	Data* nodeData;

	// While there are nodes still left
	while (node != nullptr)
	{
		nodeData = node->getData();

		absenceReport1 << nodeData->getName() << ": " << nodeData->getNumberAbsences()
			<< " absences, most recent absence: " << nodeData->getDatesOfAbsences()->peek() << std::endl;
		
		// Go to next node
		node = node->getNextPtr();
	}
}

template<class T>
void List<T>::printListbyAbsences(std::ofstream& absenceReport2, int absenceThreshold)
{
	Node<T>* node = headPtr;
	Data* nodeData;

	// While there are nodes still left
	while (node != nullptr)
	{
		nodeData = node->getData();

		if (nodeData->getNumberAbsences() >= absenceThreshold)
		{
			absenceReport2 << nodeData->getName() << " (" << nodeData->getNumberAbsences() << " absences)"
				<< std::endl;
		}
		
		// Go to next node
		node = node->getNextPtr();
	}
}

template<class T>
void List<T>::printListIntoFile(std::fstream& master)
{
	Node<T>* node = headPtr;
	Data* nodeData;

	// While there are nodes still left
	while (node != nullptr)
	{
		nodeData = node->getData();

		master << *nodeData << std::endl;

		// Go to next node
		node = node->getNextPtr();
	}
}

template<class T>
List<T>* List<T>::operator=(List<T>* _rhs)
{
	// If we are assigning a list to itself, we don't need to do anything
	if (this == _rhs)
	{
		return *this;
	}

	// Since this operator only ever gets invoked after we have initialized our variable, our list variable currently points to a list that must be deleted before we can replace our list with a copy of the other list's linked list
	destroyList();

	// Start with beginning
	if (_rhs.headPtr == nullptr)
	{
		headPtr = nullptr;
	}
	else
	{
		// Start with the first newNode
		Node* newNode = new Node(_rhs.headPtr->getData());
		headPtr = newNode;

		// Copy the rest of the newNodes
		Node* currentNode = _rhs.headPtr->getNextPtr();

		while (currentNode != nullptr)
		{
			// Copy the newNode
			Node* newNode = new Node(currentNode->getData());

			// Add the newNode to the end of the list
			newNode->setNextPtr(newNode);

			// Record the last newNode in the list
			newNode = newNode;
		}
	}

	// Return this list itself
	return *this;
}

#endif