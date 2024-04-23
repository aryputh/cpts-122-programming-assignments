/*
	Aryan Puthran
	Class: CptS 122, Spring 2024
	Lab Section: 06
	Assignment: Programming Assignment 2
	Date: 1/25/2024
	Description: This program uses a doubly linked list to keep track of a playlist. In addition, the
		program can perform functions on the playlist.
*/

#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include "testfunctions.h"

int main()
{
	// Declare required variables
	int userChoice = -1, printSpecificMode = -1, sortSpecificMode = -1, newRating = -1, characterToCheck = -1;
	Node* pStart = NULL, * pTestStart = NULL;
	char artistName[50] = "", recordName[50] = "", lineOfData[300] = "";

	// Display a welcome message
	printf("Welcome to the music manager!\n");

	// Repeat until player chooses to exit or if the file doesn't open correctly
	do
	{
		// Do the command based on player's input
		switch (userChoice)
		{
		case 1:
			// Load the songs
			loadRecords(&pStart);
			break;
		case 2:
			// Store the songs
			storeRecords(pStart);
			break;
		case 3:
			// Display the whole or artist specified playlist
			// Ask user for which mode they want
			printf("\nWhat would you like to display?\n0 - All songs\n1 - A specific artist\n");
			scanf("%d", &printSpecificMode);

			// Clear out the remaining characters
			characterToCheck = getchar();
			while (characterToCheck != '\n' && characterToCheck != EOF) {
				characterToCheck = getchar();
			}

			// Get artist name if that mode is chosen
			if (printSpecificMode == 1)
			{
				printf("\nWhich artist do you want to display?\n");
				fgets(artistName, sizeof(artistName), stdin);
			}
			
			// Display the records
			displayRecords(pStart, printSpecificMode, artistName);
			break;
		case 4:
			// Insert a song
			// Clear out the remaining characters
			characterToCheck = getchar();
			while (characterToCheck != '\n' && characterToCheck != EOF) {
				characterToCheck = getchar();
			}

			// Ask for new record values
			printf("\nWhat are the values of the new record?\n");
			printf("Format: \n1. \"LastName, FirstName\",AlbumTitle,SongTitle,Genre,SongLengthMinutes:SongLengthSeconds,NumberTimesPlayed,SongRating\n");
			printf("2. Name,AlbumTitle,SongTitle,Genre,SongLengthMinutes:SongLengthSeconds,NumberTimesPlayed,SongRating\n");
			fgets(lineOfData, sizeof(lineOfData), stdin);

			// Parse and insert the record
			insertRecord(&pStart, lineOfData);
			break;
		case 5:
			// Delete a song
			// Clear out the remaining characters
			characterToCheck = getchar();
			while (characterToCheck != '\n' && characterToCheck != EOF) {
				characterToCheck = getchar();
			}

			// Ask user for song title
			printf("\nWhat is the song you want to delete?\n");
			fgets(recordName, sizeof(recordName), stdin);

			// Delete the record
			deleteRecord(&pStart, recordName);
			break;
		case 6:
			// Edit a song
			// Clear out the remaining characters
			characterToCheck = getchar();
			while (characterToCheck != '\n' && characterToCheck != EOF) {
				characterToCheck = getchar();
			}

			// Ask user for which mode they want
			printf("\nWhat is the name of the artist whose record you want to edit?\n");
			fgets(artistName, sizeof(artistName), stdin);

			// Display the records
			displayRecords(pStart, 1, artistName);

			// Ask user for song title
			printf("\nWhat is the song you want to edit?\n");
			fgets(recordName, sizeof(recordName), stdin);

			// Ask for new record values
			printf("\nWhat are the values of the new edited record?\n");
			printf("Format: \n1. \"LastName, FirstName\",AlbumTitle,SongTitle,Genre,SongLengthMinutes:SongLengthSeconds,NumberTimesPlayed,SongRating\n");
			printf("2. Name,AlbumTitle,SongTitle,Genre,SongLengthMinutes:SongLengthSeconds,NumberTimesPlayed,SongRating\n");
			fgets(lineOfData, sizeof(lineOfData), stdin);

			// Edit the record
			editRecord(pStart, recordName, lineOfData);
			break;
		case 7:
			// Sort the playlist
			// Ask user for which mode they want
			printf("\nWhat would you like to sort by?\n1 - Artist name (A-Z)\n2 - Album name (A-Z)\n3 - Rating (1-5)\n4 - Times played (0-Infinity)\n");
			scanf("%d", &sortSpecificMode);

			// Clear out the remaining characters
			characterToCheck = getchar();
			while (characterToCheck != '\n' && characterToCheck != EOF) {
				characterToCheck = getchar();
			}

			// Display the records
			sortPlaylist(&pStart, sortSpecificMode);
			break;
		case 8:
			// Rate a song
			// Clear out the remaining characters
			characterToCheck = getchar();
			while (characterToCheck != '\n' && characterToCheck != EOF) {
				characterToCheck = getchar();
			}

			// Prompt user for song title
			printf("\nWhich song do you want to rate?\n");
			fgets(recordName, sizeof(recordName), stdin);

			// Get new rating and validate it
			do
			{
				printf("\nWhat is your new rating (1 - 5)?\n");
				scanf("%d", &newRating);
			}
			while (!(newRating > 0 && newRating < 6));

			// Edit the rating of the record
			rateRecord(pStart, recordName, newRating);
			break;
		case 9:
			// Play the playlist from a song
			// Clear out the remaining characters
			characterToCheck = getchar();
			while (characterToCheck != '\n' && characterToCheck != EOF) {
				characterToCheck = getchar();
			}

			// Prompt user for song title
			printf("\nWhich song do you want to start playing at?\n");
			fgets(recordName, sizeof(recordName), stdin);

			// Start playing the playlist
			playPlaylist(pStart, recordName);
			break;
		case 10:
			// Shuffling the playlist
			shufflePlaylist(pStart);
			break;
		case 12:
			// Testing funtions
			// Test inserting
			testInsertRecord(&pTestStart);

			// Display the playlist after inserting and pause system
			displayRecords(pTestStart, 0, "N/A");
			system("pause");

			// Test deleting
			testDeleteRecord(&pTestStart);

			// Display the playlist after deleting and pause system
			displayRecords(pTestStart, 0, "N/A");
			system("pause");

			// Test shuffling
			testShuffleRecord(pTestStart);

			// Pause system
			system("pause");
			break;
		default:
			break;
		}

		// Ask the user for a command
		printf("\nWhat would you like to do?\n1 - Load songs from a file\n2 - Store songs to a file\n3 - Display songs\n4 - Insert a song\n");
		printf("5 - Delete a song\n6 - Edit a song\n7 - Sort songs\n8 - Rate a song\n9 - Play a song\n10 - Shuffle the playlist\n11 - Exit the music manager\n");
		printf("12 - Call insert, delete, and shuffle test functions\n");
		scanf("%d", &userChoice);
	}
	while (userChoice != 11);

	// Stores the most recent version of the playlis into the file
	storeRecords(pStart);

	return 0;
}