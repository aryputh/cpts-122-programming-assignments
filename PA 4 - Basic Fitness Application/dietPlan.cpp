// Include required headers
#include "dietPlan.hpp"

/*
*	Description: Creates a class object with the given variables.
*	Date: 02/19/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: A new class object has been made.
*/
DietPlan::DietPlan(std::string newPlanName, int newCalorieGoal, std::string newPlanDate)
{
	planName = newPlanName;
	calorieGoal = newCalorieGoal;
	planDate = newPlanDate;
}

/*
*	Description: Copies the variables from the given class.
*	Date: 02/19/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The member variables have been copied.
*/
DietPlan::DietPlan(DietPlan& dietPlan)
{
	planName = dietPlan.planName;
	calorieGoal = dietPlan.calorieGoal;
	planDate = dietPlan.planDate;
}

/*
	*	Description: Deconstructs the given object.
	*	Date: 02/19/2024
	*
	*	Preconditions: None.
	*	Postconditions: The object has been destroyed.
	*/
DietPlan::~DietPlan()
{
	// Print a message when this object is destroyed
	//std::cout << "Destroyed a diet plan." << std::endl;
}

/*
*	Description: Gets the variables for given values.
*	Date: 02/19/2024
*
*	Preconditions: None.
*	Postconditions: The member variables have been returned.
*/
std::string DietPlan::getDietPlanName()
{
	return planName;
}

int DietPlan::getDietPlanCalories()
{
	return calorieGoal;
}

std::string DietPlan::getDietPlanDate()
{
	return planDate;
}

/*
*	Description: Sets the variables to the given values.
*	Date: 02/19/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The member variables have been edited.
*/
void DietPlan::setDietPlanName(std::string newPlanName)
{
	planName = newPlanName;
}

void DietPlan::setDietPlanCalories(int newCalorieGoal)
{
	calorieGoal = newCalorieGoal;
}

void DietPlan::setDietPlanDate(std::string newPlanDate)
{
	planDate = newPlanDate;
}

/*
*	Description: Edits the current goal with a new value and display the updated plan.
*	Date: 02/19/2024
*
*	Preconditions: None.
*	Postconditions: The goal value has been updated.
*/
void DietPlan::editCalorieGoal()
{
	// Prompt user for goal, validate, and set it
	std::cout << "Please enter a new goal: " << std::endl;
	
	do
	{
		std::cin >> calorieGoal;
	}
	while (calorieGoal < 0);

	std::cout << std::endl;
}

/*
*	Description: Overloads the copy operator.
*	Date: 02/26/2024
*
*	Preconditions: None.
*	Postconditions: The plan has been copied.
*/
DietPlan DietPlan::operator=(DietPlan& rhs)
{
	DietPlan newPlan;

	newPlan.setDietPlanName(rhs.getDietPlanName());
	newPlan.setDietPlanCalories(rhs.getDietPlanCalories());
	newPlan.setDietPlanDate(rhs.getDietPlanDate());

	return newPlan;
}

/*
*	Description: An overloaded stream insertion function for displaying plan to the console.
*	Date: 02/19/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The plan was printed to the console.
*/
std::ostream& operator<<(std::ostream& lhs, DietPlan& rhs)
{
	lhs << rhs.getDietPlanName() << " (" << rhs.getDietPlanDate() << "): " << rhs.getDietPlanCalories() << std::endl;

	return lhs;
}

/*
*	Description: An overloaded stream insertion function for displaying plan to a file.
*	Date: 02/26/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The plan was printed to the file.
*/
std::ofstream& operator<<(std::ofstream& lhs, DietPlan& rhs)
{
	lhs << rhs.getDietPlanName() << "\n"
		<< rhs.getDietPlanCalories() << "\n"
		<< rhs.getDietPlanDate() << "\n" << std::endl;

	return lhs;
}

/*
*	Description: An overloaded stream extraction function for reading plan from a file.
*	Date: 02/26/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The plan was read from the file.
*/
std::ifstream& operator>>(std::ifstream& lhs, DietPlan& rhs)
{
	// Declare required variables
	std::string planName;
	std::string calorieGoal;
	std::string planDate;
	std::string blankLine;

	// Get the plan name
	std::getline(lhs, planName);
	rhs.setDietPlanName(planName);

	// Get the goal
	std::getline(lhs, calorieGoal);
	rhs.setDietPlanCalories(stoi(calorieGoal));

	// Get the plan date
	std::getline(lhs, planDate);
	rhs.setDietPlanDate(planDate);

	// Get the blank line
	std::getline(lhs, blankLine);

	return lhs;
}