/*
	Aryan Puthran
	Class: CptS 122, Spring 2024
	Lab Section: 06
	Assignment: Programming Assignment 1
	Date: 01/18/2024
	Description: This program filters data from a .csv file and performs calculations on the results.
*/

#include "functions.h"

int main()
{
	// Declare required variables
	FitbitData minuteData[MAX_ROWS] = { 0 };
	FILE *dataFile = NULL, *resultsFile = NULL;
	char lineOfData[100] = { '\0' }, patient[10] = { '\0' }, listOfMinutesMaxSteps[5000] = { '\0' }, longestBadSleep[25] = { '\0' };
	int minuteDataIndex = 0, currentLineNumber = 1, numberValidHeartrates = 0;
	double totalCalories = 0.0, totalDistance = 0.0, totalHeartrate = 0.0, averageHeartrate = 0.0;
	unsigned int totalFloorsWalked = 0, totalStepsTaken = 0, maxStepsTaken = 0;

	// Open the data files for reading or wiritng
	dataFile = fopen("FitbitData.csv", "r");
	resultsFile = fopen("Results.csv", "w");

	// Ensure the files opened sucessfully
	if (dataFile != NULL && resultsFile != NULL)
	{
		// Scan each line while there is still data left in the file
		while (fgets(lineOfData, 100, dataFile) != NULL)
		{
			// Get patient ID from first line, ignores second line, and scans rest of lines
			if (currentLineNumber == 1)
			{
				// Gets the patient ID
				strcpy(patient, getPatientId(lineOfData));
			}
			else if (currentLineNumber == 2)
			{
				// Skips the second line, which is full of garbage values
			}
			else
			{
				// Remove newline character if present
				if (lineOfData[strlen(lineOfData) - 1] == '\n')
				{
					lineOfData[strlen(lineOfData) - 1] = '\0';
				}
				
				// Ensures the data is only used if the patient ID matches
				if (checkIncomingDataLine(patient, lineOfData) == 1)
				{
					// Fills invalid values with acceptable ones, and populates a struct in the array
					fillCheckedDataLine(patient, lineOfData, minuteData, &minuteDataIndex);
					
					// Increment minute data index by 1
					minuteDataIndex++;
				}
			}

			// Increment current line number by 1
			currentLineNumber++;
		}

		// Find totals and average
		calculateTotals(&totalCalories, &totalDistance, &totalHeartrate, &averageHeartrate,
			&totalFloorsWalked, &totalStepsTaken, &numberValidHeartrates, minuteData);

		// Find max steps and minutes for those steps
		findMaxSteps(&maxStepsTaken, listOfMinutesMaxSteps, minuteData);

		// Find the range of the longest bad sleep
		findBadSleepRange(longestBadSleep, minuteData);

		// Print output to results file
		fprintf(resultsFile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps(minutes),Sleep\n");
		fprintf(resultsFile, "%lf,%lf,%u,%u,%lf,%u(%s),%s", totalCalories, totalDistance, totalFloorsWalked, totalStepsTaken, averageHeartrate, maxStepsTaken, listOfMinutesMaxSteps, longestBadSleep);

		// Print the cleansed data to the file
		printCleanedData(resultsFile, minuteData);
		
		// Close the file streams
		fclose(dataFile);
		fclose(resultsFile);
	}
	else
	{
		printf("The data file failed to open successfully.");
	}

	return 0;
}