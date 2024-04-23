// Include required headers
#include "fitnessAppWrapper.hpp"

/*
*	Description: Reads one record from the file.
*	Date: 2/19/2024
*
*	Preconditions: fileStream has been opened and xPlan has valid values.
*	Postconditions: A plan has been loaded.
*/
void FitnessAppWrapper::loadDailyPlan(std::ifstream& fileStream, DietPlan& dietPlan)
{
	fileStream >> dietPlan;
}

void FitnessAppWrapper::loadDailyPlan(std::ifstream& fileStream, ExercisePlan& exercisePlan)
{
	fileStream >> exercisePlan;
}

/*
*	Description: Reads one record from the file.
*	Date: 2/19/2024
*
*	Preconditions: fileStream has been opened and weeklyXPlan has valid values.
*	Postconditions: A weekly plan has been loaded.
*/
void FitnessAppWrapper::loadWeeklyPlan(std::ifstream& fileStream, DietPlan weeklyDietPlan[])
{
	DietPlan currentDietPlan;

	// Traverse weekly plan array and load each element
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, currentDietPlan);

		weeklyDietPlan[i] = currentDietPlan;
	}
}

void FitnessAppWrapper::loadWeeklyPlan(std::ifstream& fileStream, ExercisePlan weeklyExercisePlan[])
{
	ExercisePlan currentDietPlan;

	// Traverse weekly plan array and load each element
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, currentDietPlan);

		weeklyExercisePlan[i] = currentDietPlan;
	}
}

/*
*	Description: Displays a plan to the console.
*	Date: 2/19/2024
*
*	Preconditions: xPlan has valid values.
*	Postconditions: A plan has been printed to the screen.
*/
void FitnessAppWrapper::displayDailyPlan(DietPlan dietPlan)
{
	std::cout << dietPlan;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan exercisePlan)
{
	std::cout << exercisePlan;
}

/*
*	Description: Displays the weekly plan to the console.
*	Date: 2/19/2024
*
*	Preconditions: weeklyXPlan has valid values.
*	Postconditions: A weekly plan has been printed to the screen.
*/
void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyDietPlan[])
{
	// Traverse weekly plan array and display each element
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyDietPlan[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyExercisePlan[])
{
	// Traverse weekly plan array and display each element
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyExercisePlan[i]);
	}
}

/*
*	Description: Writes a plan to a file.
*	Date: 2/26/2024
*
*	Preconditions: xPlan has valid values.
*	Postconditions: A plan has been printed to the screen.
*/
void FitnessAppWrapper::storeDailyPlan(std::ofstream& fileStream, DietPlan dietPlan)
{
	fileStream << dietPlan;
}

void FitnessAppWrapper::storeDailyPlan(std::ofstream& fileStream, ExercisePlan exercisePlan)
{
	fileStream << exercisePlan;
}

/*
*	Description: Writes a weekly plan to a file.
*	Date: 2/19/2024
*
*	Preconditions: weeklyXPlan has valid values.
*	Postconditions: A weekly plan has been printed to the screen.
*/
void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, DietPlan weeklyDietPlan[])
{
	// Traverse weekly plan array and store each element
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, weeklyDietPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, ExercisePlan weeklyExercisePlan[])
{
	// Traverse weekly plan array and store each element
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, weeklyExercisePlan[i]);
	}
}

/*
*	Description: Welcomes the user with some art.
*	Date: 2/26/2024
*
*	Preconditions: None.
*	Postconditions: Some welcome art is displayed.
*/
void FitnessAppWrapper::welcomeUser()
{
	// Print out the art line by line
	std::cout << " __          __    _                               _ \n"
		<< " \\ \\        / /   | |                             | |\n"
		<< "  \\ \\  /\\  / /___ | |  ___  ___   _ __ ___    ___ | |\n"
		<< "   \\ \\/  \\/ // _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\| |\n"
		<< "    \\  /\\  /|  __/| || (__| (_) || | | | | ||  __/|_|\n"
		<< "     \\/  \\/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|(_)\n" << std::endl;
}

/*
*	Description: Starts the application.
*	Date: 2/19/2024
*
*	Preconditions: None.
*	Postconditions: The app starts running.
*/
void FitnessAppWrapper::runApp()
{
	int menuChoice = -1;
	int planToEdit = 0;
	int newGoalValue = 0;

	// Keep going until user decides to exit
	do
	{
		// Ask user for their choice
		displayMenu();
		std::cin >> menuChoice;

		// Do different actions depending on their choice
		switch (menuChoice)
		{
		case 1: // Load weekly diet plan from file
			// Open the file stream
			inputDietStream.open("dietPlans.txt", std::ios::in);

			// Load weekly plan
			if (inputDietStream.is_open())
			{
				loadWeeklyPlan(inputDietStream, dietPlans);
			}

			// Close the file stream
			inputDietStream.close();
			break;
		case 2: // Load weekly exercise plan from file
			// Open the file stream
			inputExerciseStream.open("exercisePlans.txt", std::ios::in);

			// Load weekly plan
			if (inputExerciseStream.is_open())
			{
				loadWeeklyPlan(inputExerciseStream, exercisePlans);
			}

			// Close the file stream
			inputExerciseStream.close();
			break;
		case 3: // Store weekly diet plan to file
			// Open the file stream
			outputDietStream.open("dietPlans.txt", std::ios::out);

			// Store weekly plan
			if (outputDietStream.is_open())
			{
				storeWeeklyPlan(outputDietStream, dietPlans);
			}

			// Close the file stream
			outputDietStream.close();
			break;
		case 4: // Store weekly exercise plan to file
			// Open the file stream
			outputExerciseStream.open("exercisePlans.txt", std::ios::out);

			// Store weekly plan
			if (outputExerciseStream.is_open())
			{
				storeWeeklyPlan(outputExerciseStream, exercisePlans);
			}

			// Close the file stream
			outputExerciseStream.close();
			break;
		case 5: // Display weekly diet plan to console
			// Display weekly plan
			displayWeeklyPlan(dietPlans);
			break;
		case 6: // Display weekly exercise plan to console
			// Display weekly plan
			displayWeeklyPlan(exercisePlans);
			break;
		case 7: // Edit daily diet plan
			// Display weekly plan
			displayWeeklyPlan(dietPlans);

			// Prompt user for index and validate
			std::cout << "Please provide an index to edit: " << std::endl;

			do
			{
				std::cin >> planToEdit;
			}
			while (planToEdit < 0 || planToEdit > 6);

			// Actually update the plan
			dietPlans[planToEdit].editCalorieGoal();

			// Print weekly plan with updated plan
			displayWeeklyPlan(dietPlans);
			break;
		case 8: // Edit daily weekly plan
			// Display weekly plan
			displayWeeklyPlan(exercisePlans);

			// Prompt user for index and validate
			std::cout << "Please provide an index to edit: " << std::endl;

			do
			{
				std::cin >> planToEdit;
			}
			while (planToEdit < 0 || planToEdit > 6);

			// Actually update the plan
			exercisePlans[planToEdit].editStepsGoal();

			// Print weekly plan with updated plan
			displayWeeklyPlan(exercisePlans);
			break;
		case 9: // Write weekly plans to the file and exit the app
			exitTheApp();
			break;
		default: // In case something invalid was inputted
			std::cout << "That's not a valid choice.";
			break;
		}
	}
	while (menuChoice != 9);
}

/*
*	Description: Displays a menu of options.
*	Date: 2/19/2024
*
*	Preconditions: None.
*	Postconditions: A menu is displayed.
*/
void FitnessAppWrapper::displayMenu()
{
	// Print out all the options
	std::cout << "1. Load weekly diet plans from file.\n"
		<< "2. Load weekly exercise plans from file.\n"
		<< "3. Store weekly diet plan to file.\n"
		<< "4. Store weekly exercise plan to file.\n"
		<< "5. Display weekly diet plan to screen.\n"
		<< "6. Display weekly exercise plan to screen.\n"
		<< "7. Edit daily diet plan.\n"
		<< "8. Edit daily exercise plan.\n"
		<< "9. Exit the app." << std::endl;
}

/*
*	Description: Writes the plans to a the files and closes the stream and exits the app.
*	Date: 2/26/2024
*
*	Preconditions: None.
*	Postconditions: Plans have been stored to their respective files.
*/
void FitnessAppWrapper::exitTheApp()
{
	// Open the file streams
	outputDietStream.open("dietPlans.txt", std::ios::out);
	outputExerciseStream.open("exercisePlans.txt", std::ios::out);

	// Store weekly plans
	storeWeeklyPlan(outputDietStream, dietPlans);
	storeWeeklyPlan(outputExerciseStream, exercisePlans);

	// Close the file streams
	outputDietStream.close();
	outputExerciseStream.close();
}