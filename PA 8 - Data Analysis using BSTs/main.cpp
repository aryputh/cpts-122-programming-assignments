#include "DataAnalysis.hpp"

int main()
{
	// Declare required variables
	DataAnalysis dataAnalysis;

	// Run the analysis
	dataAnalysis.runAnalysis();

	// Notify user o complete analysis
	std::cout << "\a\nAnalysis Complete!" << std::endl;

	return 0;
}