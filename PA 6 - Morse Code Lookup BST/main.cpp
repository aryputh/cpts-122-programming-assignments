#include "bst.hpp"
#include "bstNode.hpp"

int main()
{
	// Declare required variables
	BST morseTableTree;
	std::ifstream inputFile;
	std::string lineOfData;

	// Print out all the letters in the lookup tree
	morseTableTree.print();

	// Open the input file with read mode
	inputFile.open("Convert.txt", std::ios::in);

	// Check the file opened successfully
	if (inputFile.is_open())
	{
		// Read in the contents of the input file
		while (std::getline(inputFile, lineOfData))
		{
			// Convert each character in the read in line to morse code and print to screen
			for (int i = 0; i < lineOfData.size(); i++)
			{
				// Replace spaces with 3 spaces or print the chracter in morse code
				if (lineOfData[i] == ' ')
				{
					std::cout << "   ";
				}
				else
				{
					std::cout << morseTableTree.search(toupper(lineOfData[i])) << " ";
				}
			}

			// Print a newline after each line
			std::cout << "\n" << std::endl;
		}

		// Close the file
		inputFile.close();
	}
	else
	{
		std::cout << "The convert file didn't open successfully.";
	}

	return 0;
}