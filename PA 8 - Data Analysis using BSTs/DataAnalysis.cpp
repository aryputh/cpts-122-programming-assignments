#include "DataAnalysis.hpp"

// Opens the file stream
void DataAnalysis::openStream()
{
	csvStream.open("data.csv", std::ios::in);
}

// Closes the file stream
void DataAnalysis::closeStream()
{
	csvStream.close();
}

//  Reads one line from the file and splits the line into units, type, and transaction fields
void DataAnalysis::parseLineOfData(bool tossData, int& _transUnits, std::string& _transData, std::string& _transType)
{
	// Declare required variables
	std::string _lineOfData = "";

	// If the stream is open
	if (csvStream.is_open())
	{
		// Get the line of data
		std::getline(csvStream, _lineOfData);

		if (!tossData)
		{
			// Split the line into fields
			_transUnits = stoi(_lineOfData.substr(0, _lineOfData.find(",", 0)));
			_lineOfData = _lineOfData.substr(_lineOfData.find(",", 0) + 1);
			_transData = _lineOfData.substr(0, _lineOfData.find(",", 0));
			_lineOfData = _lineOfData.substr(_lineOfData.find(",", 0) + 1);
			_transType = _lineOfData.substr(0, _lineOfData.find(",", 0));
		}
		else
		{
			std::cout << "Tossed line of data!" << std::endl;
		}
	}
	else
	{
		std::cout << "File couldn't be opened (parseLineOfData())!" << std::endl;
	}
}

// A function that loops until all lines are read from the file, calls insertDataInBSTs(), and displays BST contents
void DataAnalysis::importDataManageBSTs()
{
	std::string _lineOfData = "";
	int _numberLinesRead = 0;

	int _transUnits;
	std::string _transData;
	std::string _transType;

	// If the stream is open
	if (csvStream.is_open())
	{
		// While there is stuff to read in
		while (!csvStream.eof())
		{
			// Skip the first line of data
			if (_numberLinesRead != 0)
			{
				// Get data for the new line
				parseLineOfData(false, _transUnits, _transData, _transType);

				// Insert node into BSTs
				insertDataInBSTs(_transUnits, _transData, _transType);
			}
			else
			{
				// Toss data for the new line
				parseLineOfData(true, _transUnits, _transData, _transType);
			}

			_numberLinesRead++;
		}

		// Display contents of trees
		std::cout << "Sold tree:" << std::endl;
		soldTree.inOrderTraversal();

		std::cout << "Purchased tree:" << std::endl;
		purchasedTree.inOrderTraversal();

		// Find the trends with the trees
		displayTrends();
	}
	else
	{
		std::cout << "File couldn't be opened (importDataManageBSTs())!" << std::endl;
	}
}

// A function that compares the transaction field and inserts the units and type into the appropriate tree
void DataAnalysis::insertDataInBSTs(int _transUnits, std::string _transData, std::string _transType)
{
	// Insert node into BSTs depending on transaction type
	if (_transType == "Sold")
	{
		soldTree.insertNode(_transData, _transUnits);
	}
	else if (_transType == "Purchased")
	{
		purchasedTree.insertNode(_transData, _transUnits);
	}
	else
	{
		std::cout << "Unknown transaction type found!" << std::endl;
	}
}

// A function that writes to the screen the trends we see in our tree
void DataAnalysis::displayTrends()
{
	// Finds the most/least purchased
	std::cout << "Most purchased:" << std::endl;
	purchasedTree.findLargest().printData();
	std::cout << "Least purchased:" << std::endl;
	purchasedTree.findSmallest().printData();
	std::cout << std::endl;

	// Finds the most/least sold
	std::cout << "Most sold:" << std::endl;
	soldTree.findLargest().printData();
	std::cout << "Least sold:" << std::endl;
	soldTree.findSmallest().printData();
}

// Runs all the functions in ths class
void DataAnalysis::runAnalysis()
{
	// Open the file stream
	openStream();

	// Read in and parse lines of data, while there is something in the file, insert data into BSTs
	importDataManageBSTs();

	// Close the file stream
	closeStream();
}