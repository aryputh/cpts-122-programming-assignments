// Include required headers
#include "exercisePlan.hpp"

/*
*	Description: Creates a class object with the given variables.
*	Date: 02/19/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: A new class object has been made.
*/
ExercisePlan::ExercisePlan(std::string newPlanName, int newStepsGoal, std::string newPlanDate)
{
	planName = newPlanName;
	stepsGoal = newStepsGoal;
	planDate = newPlanDate;
}

/*
*	Description: Copies the variables from the given class.
*	Date: 02/19/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The member variables have been copied.
*/
ExercisePlan::ExercisePlan(ExercisePlan& exercisePlan)
{
	planName = exercisePlan.planName;
	stepsGoal = exercisePlan.stepsGoal;
	planDate = exercisePlan.planDate;
}

/*
	*	Description: Deconstructs the given object.
	*	Date: 02/19/2024
	*
	*	Preconditions: None.
	*	Postconditions: The object has been destroyed.
	*/
ExercisePlan::~ExercisePlan()
{
	// Print a message when this object is destroyed
	//std::cout << "Destroyed an exercise plan." << std::endl;
}

/*
*	Description: Gets the variables for given values.
*	Date: 02/19/2024
*
*	Preconditions: None.
*	Postconditions: The member variables have been returned.
*/
std::string ExercisePlan::getExercisePlanName()
{
	return planName;
}

int ExercisePlan::getExercisePlanSteps()
{
	return stepsGoal;
}

std::string ExercisePlan::getExercisePlanDate()
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
void ExercisePlan::setExercisePlanName(std::string newPlanName)
{
	planName = newPlanName;
}

void ExercisePlan::setExercisePlanSteps(int newStepsGoal)
{
	stepsGoal = newStepsGoal;
}

void ExercisePlan::setExercisePlanDate(std::string newPlanDate)
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
void ExercisePlan::editStepsGoal()
{
	// Prompt user for goal, validate, and set it
	std::cout << "Please enter a new goal: " << std::endl;

	do
	{
		std::cin >> stepsGoal;
	}
	while (stepsGoal < 0);

	std::cout << std::endl;
}

/*
*	Description: Overloads the copy operator.
*	Date: 02/26/2024
*
*	Preconditions: None.
*	Postconditions: The plan has been copied.
*/
ExercisePlan ExercisePlan::operator=(ExercisePlan& rhs)
{
	ExercisePlan newPlan;

	newPlan.setExercisePlanName(rhs.getExercisePlanName());
	newPlan.setExercisePlanSteps(rhs.getExercisePlanSteps());
	newPlan.setExercisePlanDate(rhs.getExercisePlanDate());

	return newPlan;
}

/*
*	Description: An overloaded stream insertion function for displaying plan to the console.
*	Date: 02/19/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The plan was printed to the console.
*/
std::ostream& operator<<(std::ostream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getExercisePlanName() << " (" << rhs.getExercisePlanDate() << "): " << rhs.getExercisePlanSteps() << std::endl;

	return lhs;
}

/*
*	Description: An overloaded stream insertion function for displaying plan to a file.
*	Date: 02/26/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The plan was printed to the file.
*/
std::ofstream& operator<<(std::ofstream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getExercisePlanName() << "\n"
		<< rhs.getExercisePlanSteps() << "\n"
		<< rhs.getExercisePlanDate() << "\n" << std::endl;

	return lhs;
}

/*
*	Description: An overloaded stream extraction function for reading plan from a file.
*	Date: 02/26/2024
*
*	Preconditions: Arguments are valid.
*	Postconditions: The plan was read from the file.
*/
std::ifstream& operator>>(std::ifstream& lhs, ExercisePlan& rhs)
{
	// Declare required variables
	std::string planName;
	std::string stepsGoal;
	std::string planDate;
	std::string blankLine;

	// Get the plan name
	std::getline(lhs, planName);
	rhs.setExercisePlanName(planName);

	// Get the goal
	std::getline(lhs, stepsGoal);
	rhs.setExercisePlanSteps(stoi(stepsGoal));

	// Get the plan date
	std::getline(lhs, planDate);
	rhs.setExercisePlanDate(planDate);

	// Get the blank line
	std::getline(lhs, blankLine);

	return lhs;
}