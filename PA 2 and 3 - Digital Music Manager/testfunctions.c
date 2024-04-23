/*
	Aryan Puthran
	Class: CptS 122, Spring 2024
	Lab Section: 06
	Assignment: Programming Assignment 2
	Date: 1/25/2024
	Description: This program uses a doubly linked list to keep track of a playlist. In addition, the
		program can perform functions on the playlist.
*/

#include "testfunctions.h"

/*
*	Description: This function will be used to test the insert function.
*	Date: 2/3/24
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The test record has been inserted.
*/
void testInsertRecord(Node** pStart)
{
	// Declare required variables
	char lineOfData[300] = "\"Perry, Katy\",Witness,Chained to the Rhythm,Pop,4:36,-1,6";
	
	// Insert a record with the specified data
	insertRecord(pStart, lineOfData);
}

/*
*	Description: This function will be used to test the delete function.
*	Date: 2/3/24
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The test record has been deleted.
*/
void testDeleteRecord(Node** pStart)
{
	// Declare required variables
	char songTitle[50] = "Chained to the Rhythm";

	// Delete a record with the specified data
	deleteRecord(pStart, songTitle);
}

/*
*	Description: This function will be used to test the shuffle function.
*	Date: 2/3/24
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The playlist has been shuffled.
*/
void testShuffleRecord(Node* pStart)
{
	// Declare required variables
	char lineOfData[300] = "\"Perry, Katy\",Witness,Chained to the Rhythm,Pop,4:36,-1,6";
	int playOrderArray[3] = {3, 1, 2};

	// Insert 3 songs of my choosing
	insertRecord(&pStart, lineOfData);

	strcpy(lineOfData, "\"Carlton, Vanessa\",Be Not Nobody,A Thousand Miles,Pop,3:57,3,13");
	insertRecord(&pStart, lineOfData);

	strcpy(lineOfData, "\"88, The\",Community,At Least It Was Here,Pop,2:48,4,7");
	insertRecord(&pStart, lineOfData);

	// Display the songs inserted
	displayRecords(pStart, 0, "N/A");

	// Shuffle and play the playlist
	shufflePlaylistManual(pStart, playOrderArray);
}