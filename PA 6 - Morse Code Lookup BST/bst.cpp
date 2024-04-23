#include "bst.hpp"

// A constructor that opens the file, reads in the morse table, populates the tree, and closes the file
BST::BST()
{
	this->rootPtr = nullptr;
    std::string lineOfData;

    // Open the file
	inputFile.open("MorseTable.txt", std::ifstream::in);

    // Check the file opened successfully
    if (!inputFile.is_open())
    {
        std::cout << "The morse table file didn't open successfully.";
        return;
    }

    // Read character and Morse code string from the file until the end
    while (std::getline(inputFile, lineOfData))
    {
        // Find the position of the slash
        size_t delimiterPos = lineOfData.find('/');

        // Extract the character and code using substring
        std::string englishLetter = lineOfData.substr(0, delimiterPos);
        std::string morseCodeString = lineOfData.substr(delimiterPos + 1);

        // Create and insert a new node
        BSTNode* newNode = new BSTNode(englishLetter[0], morseCodeString);
        insert(newNode, rootPtr);
    }

    // Close the file
    inputFile.close();
}

// A destructor for the class that calls a private member function
BST::~BST()
{
    // Destroy the the tree
    destroyTree(rootPtr);
}

// Inserts a node created from a given character and morse string
void BST::insert(char character, const std::string& morse)
{
    // Create and insert the node into the tree
    BSTNode* newNode = new BSTNode(character, morse);
    insert(newNode, rootPtr);
}

// Prints out the entire tree
void BST::print()
{
    // Start printing from the root node
    print(rootPtr);
}

// Searches for a given character
std::string BST::search(char character)
{
    // Searches for the character given and returns to morse string associated with that
    if (search(character, rootPtr) != nullptr)
    {
        return search(character, rootPtr)->getMorseCodeString();
    }
    else
    {
        return "INVALID";
    }
}

// Inserts a node
void BST::insert(BSTNode* newNode, BSTNode* nodePtr)
{
    if (nodePtr == nullptr)
    {
        // Add the node to the current position, if the tree is empty
        rootPtr = newNode;
    }
    else if (newNode->getEnglishLetter() < nodePtr->getEnglishLetter())
    {
        // Insert node into the left side
        if (nodePtr->getLeftPtr() == nullptr)
        {
            nodePtr->setLeftPtr(newNode);
        }
        else
        {
            insert(newNode, nodePtr->getLeftPtr());
        }
    }
    else if (newNode->getEnglishLetter() > nodePtr->getEnglishLetter())
    {
        // Insert node into the right side
        if (nodePtr->getRightPtr() == nullptr)
        {
            nodePtr->setRightPtr(newNode);
        }
        else
        {
            insert(newNode, nodePtr->getRightPtr());
        }
    }
    else
    {
        // If the node is a duplicate
        std::cout << "A duplicate node was detected!";
        return;
    }
}

// Prints the entire tree recursively
void BST::print(BSTNode* nodePtr)
{
    if (nodePtr != nullptr)
    {
        // Print the left side, and then the right side
        print(nodePtr->getLeftPtr());
        std::cout << nodePtr->getEnglishLetter() << " " << nodePtr->getMorseCodeString() << std::endl;
        print(nodePtr->getRightPtr());
    }
}

// Searches for a character and returns a pointer to the node
BSTNode* BST::search(char character, BSTNode* nodePtr)
{
    if (nodePtr == nullptr || nodePtr->getEnglishLetter() == character)
    {
        // Return the pointer if the character is found or if the character isn't found
        return nodePtr;
    }
    else if (character < nodePtr->getEnglishLetter())
    {
        // Search on the left side
        return search(character, nodePtr->getLeftPtr());
    }
    else
    {
        // Search on the right sde
        return search(character, nodePtr->getRightPtr());
    }
}

// Destroys the tree
void BST::destroyTree(BSTNode* nodePtr)
{
    // Ensure the tree isn't empty
    if (nodePtr != nullptr)
    {
        // Destroy the left and right nodes
        destroyTree(nodePtr->getLeftPtr());
        destroyTree(nodePtr->getRightPtr());
        delete nodePtr;
    }
}