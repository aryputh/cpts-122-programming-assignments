#pragma once

// Include required headers
#include "masterHeader.hpp"

class FitnessAppWrapper
{
private:
	// Declare required private variables
	DietPlan dietPlans[7];
	ExercisePlan exercisePlans[7];
	std::ifstream inputDietStream;
	std::ifstream inputExerciseStream;
	std::ofstream outputDietStream;
	std::ofstream outputExerciseStream;

	// Declare function prototypes
	void loadDailyPlan(std::ifstream& fileStream, DietPlan& dietPlan);
	void loadDailyPlan(std::ifstream& fileStream, ExercisePlan& exercisePlan);
	void loadWeeklyPlan(std::ifstream& fileStream, DietPlan weeklyDietPlan[]);
	void loadWeeklyPlan(std::ifstream& fileStream, ExercisePlan weeklyExercisePlan[]);
	void displayDailyPlan(DietPlan dietPlan);
	void displayDailyPlan(ExercisePlan exercisePlan);
	void displayWeeklyPlan(DietPlan weeklyDietPlan[]);
	void displayWeeklyPlan(ExercisePlan weeklyExercisePlan[]);
	void storeDailyPlan(std::ofstream& fileStream, DietPlan dietPlan);
	void storeDailyPlan(std::ofstream& fileStream, ExercisePlan exercisePlan);
	void storeWeeklyPlan(std::ofstream& fileStream, DietPlan weeklyDietPlan[]);
	void storeWeeklyPlan(std::ofstream& fileStream, ExercisePlan weeklyExercisePlan[]);

public:
	// Declare function prototypes
	void welcomeUser();
	void runApp();
	void displayMenu();
	void exitTheApp();
};