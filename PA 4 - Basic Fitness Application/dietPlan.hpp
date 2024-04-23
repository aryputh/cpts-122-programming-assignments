#pragma once

// Include required headers
#include "masterHeader.hpp"

class DietPlan
{
private:
	// Declare required private variables
	std::string planName;
	int calorieGoal;
	std::string planDate;

public:
	// Declare function prototypes
	DietPlan(std::string newPlanName = "N/A", int newCalorieGoal = 0, std::string newPlanDate = "00/00/0000");
	DietPlan(DietPlan& dietPlan);
	~DietPlan();

	std::string getDietPlanName();
	int getDietPlanCalories();
	std::string getDietPlanDate();

	void setDietPlanName(std::string newPlanName);
	void setDietPlanCalories(int newCalorieGoal);
	void setDietPlanDate(std::string newPlanDate);

	void editCalorieGoal();

	DietPlan operator=(DietPlan& rhs);
};

// Declare function prototypes
std::ostream& operator<<(std::ostream& lhs, DietPlan& rhs);
std::ofstream& operator<<(std::ofstream& lhs, DietPlan& rhs);
std::ifstream& operator>>(std::ifstream& lhs, DietPlan& rhs);