// Include required headers
#include "masterHeader.hpp"
#include "dietPlan.hpp"
#include "exercisePlan.hpp"
#include "fitnessAppWrapper.hpp"

int main()
{
	// Declare required variables
	FitnessAppWrapper appWrapper;

	// Welcome the user
	appWrapper.welcomeUser();

	// Run the app
	appWrapper.runApp();

	return 0;
}