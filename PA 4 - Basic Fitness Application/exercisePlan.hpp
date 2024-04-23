#pragma once

// Include required headers
#include "masterHeader.hpp"

class ExercisePlan
{
private:
	// Declare required private variables
	std::string planName;
	int stepsGoal;
	std::string planDate;

public:
	// Declare function prototypes
	ExercisePlan(std::string newPlanName = "N/A", int newStepsGoal = 0, std::string newPlanDate = "00/00/0000");
	ExercisePlan(ExercisePlan& exercisePlan);
	~ExercisePlan();

	std::string getExercisePlanName();
	int getExercisePlanSteps();
	std::string getExercisePlanDate();

	void setExercisePlanName(std::string newPlanName);
	void setExercisePlanSteps(int newCalorieGoal);
	void setExercisePlanDate(std::string newPlanDate);

	void editStepsGoal();

	ExercisePlan operator=(ExercisePlan& rhs);
};

// Declare function prototypes
std::ostream& operator<<(std::ostream& lhs, ExercisePlan& rhs);
std::ofstream& operator<<(std::ofstream& lhs, ExercisePlan& rhs);
std::ifstream& operator>>(std::ifstream& lhs, ExercisePlan& rhs);