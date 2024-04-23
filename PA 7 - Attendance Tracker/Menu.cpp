#include "Menu.hpp"

Menu::Menu(int _menuChoice)
{
	menuChoice = _menuChoice;
}

int Menu::getMenuChoice()
{
	return menuChoice;
}

void Menu::printOptions()
{
	// List all the options
	std::cout << "1 = Import course list\n" << "2 = Load master list\n" << "3 = Store master list\n"
		<< "4 = Mark absences\n" << "5 = Edit absences\n" << "6 = Generate report\n"
		<< "7 = Exit app" << std::endl;
}

void Menu::getUserChoice()
{
	// Prompt the user
	std::cout << "What action do you want to do?" << std::endl;

	// Get the user's choice
	std::cin >> menuChoice;
}

void Menu::runSelectedChoice()
{
	// Declare required variables
	std::string lineOfData;
	int numberLinesRead = 0;
	int recordNumber = 0;
	int idNumber = 0;
	std::string studentName = "N/A";
	std::string studentEmail = "N/A";
	std::string credits = "N/A";
	std::string studentMajor = "N/A";
	std::string studentStanding = "N/A";
	int numberAbsences = 0;
	std::vector<std::string> datesOfAbsences = std::vector<std::string>();

	// Run the functions dependant on the user's choice
	switch (menuChoice)
	{
	case 1: // Import course list

		// Destroy an existing linked list
		masterList.destroyList();

		// Open the file for reading
		classList.open("classList.csv", std::ios::in);

		// Ensure the file opened successfully
		if (classList.is_open())
		{
			// Get the line of data, while there is data left
			while (std::getline(classList, lineOfData))
			{
				// Skips the first line
				if (numberLinesRead != 0)
				{
					// Get the contents of the data
					recordNumber = stoi(lineOfData.substr(0, lineOfData.find(",", 0)));
					lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
					idNumber = stoi(lineOfData.substr(0, lineOfData.find("\"", 0)));
					lineOfData = lineOfData.substr(lineOfData.find("\"", 0) + 1);
					studentName = lineOfData.substr(0, lineOfData.find("\"", 0));
					lineOfData = lineOfData.substr(lineOfData.find("\"", 0) + 2);
					studentEmail = lineOfData.substr(0, lineOfData.find(",", 0));
					lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
					credits = lineOfData.substr(0, lineOfData.find(",", 0));
					lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
					studentMajor = lineOfData.substr(0, lineOfData.find(",", 0));
					lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
					studentStanding = lineOfData.substr(0);

					// Create and insert new node into the list
					masterList.insertAtFront(new Data(recordNumber, idNumber, studentName, studentEmail,
						credits, studentMajor, studentStanding, numberAbsences, datesOfAbsences));
				}

				numberLinesRead++;
			}

			// Close the file
			classList.close();

			// Notify user of successful import
			std::cout << "List imported successfully." << std::endl;
		}
		else
		{
			// Print out an error in case file couldn't be opened
			std::cout << "The file could not be opened." << std::endl;
		}

		break;
	case 2: // Load master list

		// Destroy an existing linked list
		masterList.destroyList();

		// Open the file for reading
		master.open("master.csv", std::ios::in);

		// Ensure the file opened successfully
		if (master.is_open())
		{
			// Get the line of data, while there is data left
			while (std::getline(master, lineOfData))
			{
				// Get the contents of the data
				recordNumber = stoi(lineOfData.substr(0, lineOfData.find(",", 0)));
				lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
				idNumber = stoi(lineOfData.substr(0, lineOfData.find("\"", 0)));
				lineOfData = lineOfData.substr(lineOfData.find("\"", 0) + 1);
				studentName = lineOfData.substr(0, lineOfData.find("\"", 0));
				lineOfData = lineOfData.substr(lineOfData.find("\"", 0) + 2);
				studentEmail = lineOfData.substr(0, lineOfData.find(",", 0));
				lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
				credits = lineOfData.substr(0, lineOfData.find(",", 0));
				lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
				studentMajor = lineOfData.substr(0, lineOfData.find(",", 0));
				lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
				studentStanding = lineOfData.substr(lineOfData.find(",", 0) + 1);
				lineOfData = lineOfData.substr(lineOfData.find(",", 0) + 1);
				numberAbsences = stoi(lineOfData.substr(0));

				// Create and insert new node into the list
				masterList.insertAtFront(new Data(recordNumber, idNumber, studentName, studentEmail,
					credits, studentMajor, studentStanding, numberAbsences, datesOfAbsences));
			}

			// Close the file
			master.close();

			// Notify user of successful import
			std::cout << "Master list imported successfully." << std::endl;
		}
		else
		{
			// Print out an error in case file couldn't be opened
			std::cout << "The file could not be opened." << std::endl;
		}

		break;
	case 3: // Store master list

		// Open the file for reading
		master.open("master.csv", std::ios::out);

		if (master.is_open())
		{
			masterList.printListIntoFile(master);

			// Close the file
			master.close();
		}
		else
		{
			// Print out an error in case file couldn't be opened
			std::cout << "The file could not be opened." << std::endl;
		}

		// Notify user of successful export
		std::cout << "Master list exported successfully." << std::endl;

		break;
	case 4: // Mark absences

		masterList.markAbsences();

		// Notify user of successful markings
		std::cout << "Absences marked successfully." << std::endl;

		break;
	case 5: // Edit absences

		std::cout << "This feature isn't implemented." << std::endl;

		break;
	case 6: // Generate report

		// Prompt user
		std::cout << "1 = Show recent absence for each student.\n" << "2 = Generate reports based on # absences." << std::endl;
		
		// Get user choice and error check
		do
		{
			std::cin >> menuChoice;
		}
		while (!(menuChoice == 1 || menuChoice == 2));

		// Print depending on user input
		if (menuChoice == 1)
		{
			absenceReport1.open("absenceReport1.txt", std::ios::out);

			if (absenceReport1.is_open())
			{
				masterList.printRecentAbsences(absenceReport1);

				// Clsoe the file
				absenceReport1.close();
			}
			else
			{
				// Print out an error in case file couldn't be opened
				std::cout << "The file could not be opened." << std::endl;
			}
		}
		else
		{
			// Prompt, get user choice and error check
			std::cout << "How many absences until student is listed?" << std::endl;
			do
			{
				std::cin >> menuChoice;
			}
			while (menuChoice <= 0);

			absenceReport2.open("absenceReport2.txt", std::ios::out);

			if (absenceReport2.is_open())
			{
				masterList.printListbyAbsences(absenceReport2, menuChoice);

				// Close the file
				absenceReport2.close();
			}
			else
			{
				// Print out an error in case file couldn't be opened
				std::cout << "The file could not be opened." << std::endl;
			}
		}

		// Notify user of successful print
		std::cout << "Absences recorded successfully." << std::endl;

		break;
	case 7: // Exit app
		std::cout << "Exiting the app..." << std::endl;
		break;
	default: // Any invalid data
		std::cout << "That's not a valid option!" << std::endl;
		break;
	}
}