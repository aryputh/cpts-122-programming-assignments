#include "BST.hpp"

// Destroys the tree with recursion
void BST::destroyTree(Node* _nodePtr)
{
	if (_nodePtr != nullptr)
	{
		destroyTree(_nodePtr->getLeftPtr());
		destroyTree(_nodePtr->getRightPtr());
		delete _nodePtr;
	}
}

// Inserts the data into the tree
void BST::insert(Node*& _nodePtr, std::string& _nodeData, int& _units)
{
	TransactionNode* _transNode = dynamic_cast<TransactionNode*>(_nodePtr);
	Node* _regularNode = new TransactionNode(_nodeData, _units);

	if (_transNode == nullptr)
	{
		rootPtr = _regularNode;
	}
	else
	{
		if (_units < dynamic_cast<TransactionNode*>(_transNode)->getUnits())
		{
			if (_transNode->getLeftPtr() == nullptr)
			{
				_transNode->setLeftPtr(_regularNode);
			}
			else
			{
				insert(_transNode->getLeftPtr(), _nodeData, _units);
			}
		}
		else if (_units > dynamic_cast<TransactionNode*>(_transNode)->getUnits())
		{
			if (_transNode->getRightPtr() == nullptr)
			{
				_transNode->setRightPtr(_regularNode);
			}
			else
			{
				insert(_transNode->getRightPtr(), _nodeData, _units);
			}
		}
		else
		{
			std::cout << "Duplicate value, not inserting this node!" << std::endl;
		}
	}
}

// Finds the smallest node by units
TransactionNode& BST::smallest(Node* _nodePtr)
{
	TransactionNode* _transNode = dynamic_cast<TransactionNode*>(_nodePtr);

	if (_nodePtr->getLeftPtr() != nullptr)
	{
		smallest(_nodePtr->getLeftPtr());
	}
	else
	{
		return *_transNode;
	}
}

// Finds the largest node by units
TransactionNode& BST::largest(Node* _nodePtr)
{
	TransactionNode* _transNode = dynamic_cast<TransactionNode*>(_nodePtr);

	if (_nodePtr->getRightPtr() != nullptr)
	{
		largest(_nodePtr->getRightPtr());
	}
	else
	{
		return *_transNode;
	}
}

// Inserts a node
void BST::insertNode(std::string _nodeData, int _units)
{
	insert(rootPtr, _nodeData, _units);
}

// Prints out entire tree
void BST::inOrderTraversal()
{
	if (rootPtr != nullptr)
	{
		inOrderTraversal(rootPtr);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Tree is empty." << std::endl;
	}
}

// Prints out the entire tree
void BST::inOrderTraversal(Node* _nodePtr)
{
	if (_nodePtr != nullptr)
	{
		inOrderTraversal(_nodePtr->getLeftPtr());
		_nodePtr->printData();
		inOrderTraversal(_nodePtr->getRightPtr());
	}
}

// Finds the smallest node by units
TransactionNode& BST::findSmallest()
{
	return smallest(rootPtr);
}

// Finds the largest node by units
TransactionNode& BST::findLargest()
{
	return largest(rootPtr);
}

BST::BST()
{
	rootPtr = nullptr;
}

BST::~BST()
{
	destroyTree(rootPtr);
}

// Gets the root pointer
Node* BST::getRootPtr()
{
	return rootPtr;
}

// Sets the root pointer
void BST::setRootPtr(Node* _rootPtr)
{
	rootPtr = _rootPtr;
}