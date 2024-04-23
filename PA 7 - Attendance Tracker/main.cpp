#include "Menu.hpp"

int main()
{
	// Declare required variables
	Menu mainMenu(-1);

	// Run the app until user decides to exit
	do
	{
		// List all the options for the user
		mainMenu.printOptions();

		// Get the user's choice and run the selected choice
		mainMenu.getUserChoice();
		mainMenu.runSelectedChoice();
	}
	while (mainMenu.getMenuChoice() != 7);

	return 0;
}