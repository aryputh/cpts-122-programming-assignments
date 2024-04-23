/*
	Aryan Puthran
	Class: CptS 122, Spring 2024
	Lab Section: 06
	Assignment: Programming Assignment 1
	Date: 01/18/2024
	Description: This program filters data from a .csv file and performs calculations on the results.
*/

// Ensures the header file is created once
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROWS 1440

// Include necessary libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare an enum for sleep levels
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

// Declare a struct for minute data
typedef struct fitbitData
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

// Function prototypes
char * getPatientId(char *lineOfData);
int checkIncomingDataLine(char *patient, char *lineOfData);
void fillCheckedDataLine(char* patient, char* lineOfData, FitbitData* minuteData, int* minuteDataIndex);
int checkForDuplicates(char minute[], FitbitData *minuteData);
char * customStrTok(char *string, char delimiter);
void calculateTotals(double* totalCalories, double* totalDistance, double* totalHeartrate, double* averageHeartrate,
	unsigned int* totalFloors, unsigned int* totalSteps, int* numberValidHeartrates, FitbitData* minuteData);
void findMaxSteps(unsigned int *maxSteps, char *listOfMinutes, FitbitData *minuteData);
void printCleanedData(FILE *resultsFile, FitbitData *minuteData);
void findBadSleepRange(char *longestBadSleep, FitbitData *minuteData);