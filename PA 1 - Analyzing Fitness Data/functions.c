/*
	Aryan Puthran
	Class: CptS 122, Spring 2024
	Lab Section: 06
	Assignment: Programming Assignment 1
	Date: 01/18/2024
	Description: This program filters data from a .csv file and performs calculations on the results.
*/

#include "functions.h"

/*
*	Description: Checks the first line of data for the patient ID.
*	Date: 01/18/2024
*
*	Preconditions: A string with 8 comma seperated values is entered.
*	Postconditions: Sets the patient ID successfully.
*/
char * getPatientId(char *lineOfData)
{
	// Declare required variables
	char *token = strtok(lineOfData, ",");

	// The patient ID in the second comma seperated value
	token = strtok(NULL, ",");
	
	return token;
}

/*
*	Description: Checks the data to ensure the patient ID matches.
*	Date: 01/18/2024
*
*	Preconditions: A string with 8 comma seperated values is entered.
*	Postconditions: Returns 1 if data is valid, 0 if data is invalid.
*/
int checkIncomingDataLine(char *patient, char *lineOfData)
{
	// Declare required variables
	char lineDuplicate[100] = "\0";
	strcpy(lineDuplicate, lineOfData);

	char * tokenPosition = strtok(lineDuplicate, ",");

	// Check if a comma is found
	if (tokenPosition != NULL)
	{
		// Check if the patient and the substring match
		if (strcmp(tokenPosition, patient) == 0)
		{
			return 1;
		}
	}

	// If the ID isn't the same or no comma is found, return 0
	return 0;
}

/*
*	Description: Fill invalid or missing data with markers.
*	Date: 01/18/2024
*
*	Preconditions: A string with 8 comma seperated values is entered. Patient and minute are valid.
*	Postconditions: The minuteData array is filled with valid values.
*/
void fillCheckedDataLine(char *patient, char *lineOfData, FitbitData *minuteData, int *minuteDataIndex)
{
	// Declare required default values, may assume patient and minute are valid
	char defaultMinute[] = "noTime";
	double defaultCalories = -1.0;
	double defaultDistance = -1.0;
	unsigned int defaultFloors = 500000;
	unsigned int defaultHeartRate = 500000;
	unsigned int defaultSteps = 500000;
	Sleep defaultSleepLevel = -1;
	char lineDuplicate[100] = "\0";
	char lineForCheckingMinute[100] = "\0";

	strcpy(lineDuplicate, lineOfData);

	// Skip through patient ID value
	char *token = customStrTok(lineDuplicate, ',');
	strcpy((minuteData + *minuteDataIndex)->patient, patient);

	// Skip through minute value
	token = customStrTok(NULL, ',');
	if (checkForDuplicates(token, minuteData) == 0)
	{
		strcpy((minuteData + *minuteDataIndex)->minute, token);
	}
	else
	{
		(*minuteDataIndex)--;
		return;
	}

	// Check calorie value
	token = customStrTok(NULL, ',');
	if (strcmp(token, "") == 0)
	{
		// If data is invalid
		(minuteData + *minuteDataIndex)->calories = defaultCalories;
	}
	else
	{
		// If data is valid
		(minuteData + *minuteDataIndex)->calories = atof(token);
	}

	// Check distance value
	token = customStrTok(NULL, ',');
	if (strcmp(token, "") == 0)
	{
		// If data is invalid
		(minuteData + *minuteDataIndex)->distance = defaultDistance;
	}
	else
	{
		// If data is valid
		(minuteData + *minuteDataIndex)->distance = atof(token);
	}

	// Check floors value
	token = customStrTok(NULL, ',');
	if (strcmp(token, "") == 0)
	{
		// If data is invalid
		(minuteData + *minuteDataIndex)->floors = defaultFloors;
	}
	else
	{
		// If data is valid
		(minuteData + *minuteDataIndex)->floors = strtoul(token, NULL, 0);
	}

	// Check heartrate value
	token = customStrTok(NULL, ',');
	if (strcmp(token, "") == 0)
	{
		// If data is invalid
		(minuteData + *minuteDataIndex)->heartRate = defaultHeartRate;
	}
	else
	{
		// If data is valid
		(minuteData + *minuteDataIndex)->heartRate = strtoul(token, NULL, 0);
	}

	// Check steps value
	token = customStrTok(NULL, ',');
	if (strcmp(token, "") == 0)
	{
		// If data is invalid
		(minuteData + *minuteDataIndex)->steps = defaultSteps;
	}
	else
	{
		// If data is valid
		(minuteData + *minuteDataIndex)->steps = strtoul(token, NULL, 0);
	}

	// Check sleep level value
	token = customStrTok(NULL, ',');
	if (strcmp(token, "") == 0)
	{
		// If data is invalid
		(minuteData + *minuteDataIndex)->sleepLevel = defaultSleepLevel;
	}
	else
	{
		// If data is valid
		(minuteData + *minuteDataIndex)->sleepLevel = atoi(token);
	}
}

/*
*	Description: Checks the data for duplicate lines and returns 1 if there is.
*	Date: 01/22/2024
*
*	Preconditions: A valid minute and minuteData is provided.
*	Postconditions: Returns 1 if data is duplicated, 0 if data is unique.
*/
int checkForDuplicates(char minute[], FitbitData *minuteData)
{
	// Check if the minute is duplicated
	for (int i = 0; i < MAX_ROWS; i++)
	{
		if (strcmp((minuteData + i)->minute, minute) == 0)
		{
			return 1;
		}
	}

	// If the minute isn't the same, return 0
	return 0;
}

/*
*	Description: Custom strtok() function also returns '\0' if a data field is empty.
*	Date: 01/20/2024
*
*	Preconditions: Valid string and delimiter are provided.
*	Postconditions: Returns a pointer to a string piece.
*/
char * customStrTok(char *string, char delimiter)
{
	// Static keyword saves the variable from being destroyed once out of scope
	static char* pToken = NULL;

	// Create the token variable
	char* token = NULL;

	// Sets the pToken as the string
	if (string)
	{
		pToken = string;
	}

	// Checks for any remaining characters
	if (!pToken)
	{
		return NULL;
	}

	// Remember pToken as an already found token
	token = pToken;

	// Find next occurrence of the deliminator
	pToken = strchr(pToken, delimiter);

	// If a delimiter is found, replace it with a null character
	if (pToken)
	{
		*pToken++ = '\0';
	}

	return token;
}

/*
*	Description: Finds the total values for calories, distance, steps, and floors.
*	Date: 01/23/2024
*
*	Preconditions: Valid arguments are provided.
*	Postconditions: Changes the total value to reflect actual values.
*/
void calculateTotals(double *totalCalories, double *totalDistance, double *totalHeartrate, double *averageHeartrate,
	unsigned int *totalFloors, unsigned int *totalSteps, int *numberValidHeartrates, FitbitData *minuteData)
{
	// Traverse array, sum numbers, and update total values
	for (int i = 0; i < MAX_ROWS - 1; i++)
	{
		if ((minuteData + i)->heartRate != 500000)
		{
			*totalHeartrate += (minuteData + i)->heartRate;
			(*numberValidHeartrates)++;
		}

		if ((minuteData + i)->calories != -1.0)
		{
			*totalCalories += (minuteData + i)->calories;
		}

		if ((minuteData + i)->distance != -1.0)
		{
			*totalDistance += (minuteData + i)->distance;
		}

		if ((minuteData + i)->floors != 500000)
		{
			*totalFloors += (minuteData + i)->floors;
		}

		if ((minuteData + i)->steps != -1)
		{
			*totalSteps += (minuteData + i)->steps;
		}
	}

	*averageHeartrate = *totalHeartrate / *numberValidHeartrates;
}

/*
*	Description: Finds the max number of steps and returns all the minutes with that value.
*	Date: 01/23/2024
*
*	Preconditions: Valid arguments are provided.
*	Postconditions: Changes the max steps and minutes to reflect actual values.
*/
void findMaxSteps(unsigned int *maxSteps, char *listOfMinutes, FitbitData *minuteData)
{
	// Traverse array, sum numbers, and update total values
	for (int i = 0; i < MAX_ROWS - 1; i++)
	{
		if ((minuteData + i)->steps > *maxSteps)
		{
			*maxSteps = (minuteData + i)->steps;
			strcpy(listOfMinutes, (minuteData + i)->minute);
			//strcat(listOfMinutes, ";");
		}
		else if ((minuteData + i)->steps == *maxSteps)
		{
			strcat(listOfMinutes, (minuteData + i)->minute);
			//strcat(listOfMinutes, ";");
		}
	}
}

/*
*	Description: Prints the cleaned data to the output file.
*	Date: 01/23/2024
*
*	Preconditions: Valid arguments are provided.
*	Postconditions: Cleaned data is printed to the file.
*/
void printCleanedData(FILE *resultsFile, FitbitData *minuteData)
{
	// Traverse array, get struct values, and print them to the file
	for (int i = 0; i < MAX_ROWS - 1; i++)
	{
		fprintf(resultsFile, "\n%s,%s,%lf,%lf,%u,%u,%u,%d", (minuteData + i)->patient, (minuteData + i)->minute, (minuteData + i)->calories,
			(minuteData + i)->distance, (minuteData + i)->floors, (minuteData + i)->heartRate, (minuteData + i)->steps,
			(minuteData + i)->sleepLevel);
	}
}

/*
*	Description: Prints the cleaned data to the output file.
*	Date: 01/23/2024
*
*	Preconditions: Valid arguments are provided.
*	Postconditions: Cleaned data is printed to the file.
*/
void findBadSleepRange(char *longestBadSleep, FitbitData *minuteData)
{
	// Declare required variables
	int sumOfBadSleep = 0;
	int tempSumOfBadSleep = 0;
	char tempBadSleepStart[15] = "00:00:00";
	char tempBadSleepEnd[15] = "00:00:00";

	// Traverse array, compare sleep, and update longest bad sleep
	for (int i = 0; i < MAX_ROWS - 1; i++)
	{
		if ((minuteData + i)->sleepLevel > 1 && tempSumOfBadSleep == 0)
		{
			strcpy(tempBadSleepStart, (minuteData + i)->minute);
			tempSumOfBadSleep += (minuteData + i)->sleepLevel;
		}
		else if ((minuteData + i)->sleepLevel == 1 && tempSumOfBadSleep != 0)
		{
			strcpy(tempBadSleepEnd, (minuteData + i - 1)->minute);

			if (tempSumOfBadSleep >= sumOfBadSleep)
			{
				sumOfBadSleep = tempSumOfBadSleep;
				strcpy(longestBadSleep, tempBadSleepStart);
				strcat(longestBadSleep, "-");
				strcat(longestBadSleep, tempBadSleepEnd);
			}
			
			tempSumOfBadSleep = 0;
		}
	}
}