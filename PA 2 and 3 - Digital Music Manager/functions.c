/*
	Aryan Puthran
	Class: CptS 122, Spring 2024
	Lab Section: 06
	Assignment: Programming Assignment 2
	Date: 1/25/2024
	Description: This program uses a doubly linked list to keep track of a playlist. In addition, the
		program can perform functions on the playlist.
*/

#include "functions.h"

/*
*	Description: Creates a node with the supplied Record values.
*	Date: 1/26/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: A new node is made with the supplied data.
*/
Node* createNode(Record* recordData)
{
	// Allocate memory for the new node
	Node *newNode = malloc(sizeof(Node));

	// Assign data and values to the node
	if (newNode != NULL)
	{
		newNode->recordData = *recordData;
		newNode->pNext = NULL;
		newNode->pPrev = NULL;
	}

	return newNode;
}

/*
*	Description: Inserts a node into the playlist.
*	Date: 1/26/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: A 1 is returned if success, 0 otherwise.
*/
int insertFront(Node** pStart, Record newRecord)
{
    // Set the new node to the right value
    Node* newNode = createNode(&newRecord);

    if (newNode == NULL)
    {
        return 0;
    }

    // Set up the connection of the new node in the playlist
    if (*pStart == NULL)
    {
        // If this is the first song in the playlist
        *pStart = newNode;
        newNode->pPrev = NULL;
        newNode->pNext = NULL;

        return 1;
    }
    else
    {
        // If another song already exists in the playlist
        newNode->pNext = *pStart;
        (*pStart)->pPrev = newNode;
        *pStart = newNode;
        newNode->pPrev = NULL;

        return 1;
    }
}

/*
*	Description: Clears the entire linked list, used when loading songs in.
*	Date: 1/28/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The linked list is cleared completely.
*/
void clearList(Node** pStart)
{
    // Declare required variables
    Node* current = *pStart;
    Node* next;

    // While there is a node left
    while (current != NULL)
    {
        next = current->pNext;
        free(current);
        current = next;
    }

    // Set the start pointer to null
    *pStart = NULL;
}


/*
*	Description: Reads in values from a file and inserts them at the front of the list.
*	Date: 1/26/2024
*
*	Preconditions: Actual arguments are valid, file has been opened.
*	Postconditions: A playlist has been made.
*/
void loadRecords(Node** pStart)
{
    // Declare required variables
    char lineOfData[300] = { '\0' };
    char* token = NULL;
    int stringLength = 0;
    Duration newDuration = { 0, 0 };
    Record newRecord;
    FILE* playlistFile = fopen("musicPlayList.csv", "r");

    // Check the file opened successfully
    if (playlistFile == NULL)
    {
        printf("\nError opening file.\n");
        return;
    }

    // Clear the existing records
    if (*pStart != NULL)
    {
        clearList(pStart);
    }

    // Reads in the records until there are no more
    while (fgets(lineOfData, 300, playlistFile) != NULL)
    {
        // Check if the artist name is enclosed in double quotes
        if (lineOfData[0] == '"')
        {
            // Get data until the second quote
            token = strtok(lineOfData, "\"");

            // Copy the artist
            strcpy(newRecord.artist, token);
        }
        else
        {
            // Get the artist
            token = strtok(lineOfData, ",");

            // Copy the artist
            strcpy(newRecord.artist, token);
        }
        
        // Continue reading other fields
        token = strtok(NULL, ",");
        strcpy(newRecord.albumTitle, token);

        token = strtok(NULL, ",");
        strcpy(newRecord.songTitle, token);

        token = strtok(NULL, ",");
        strcpy(newRecord.genre, token);

        token = strtok(NULL, ":");
        newRecord.songLength.minutes = atoi(token);

        // Ensure the minutes is positive
        if (newRecord.songLength.minutes < 0)
        {
            newRecord.songLength.minutes = 0;
        }

        token = strtok(NULL, ",");
        newRecord.songLength.seconds = atoi(token);

        // Ensure the seconds is positive and below 60
        if (newRecord.songLength.seconds < 0)
        {
            newRecord.songLength.seconds = 0;
        }
        else if (newRecord.songLength.seconds > 60)
        {
            newRecord.songLength.minutes = newRecord.songLength.seconds / 60;
            newRecord.songLength.seconds = newRecord.songLength.seconds % 60;
        }

        token = strtok(NULL, ",");
        newRecord.numberTimesPlayed = atoi(token);

        // Ensure the number of times played is positive
        if (newRecord.numberTimesPlayed < 0)
        {
            newRecord.numberTimesPlayed = 0;
        }

        token = strtok(NULL, ",");
        newRecord.rating = atoi(token);

        // Ensure the rating is between 1 and 5
        if (newRecord.rating > 5)
        {
            newRecord.rating = 5;
        }
        else if (newRecord.rating < 1)
        {
            newRecord.rating = 1;
        }

        // Create a new node
        if (insertFront(pStart, newRecord) == 0)
        {
            printf("\nInserting went wrong.\n");
        }
    }

    // Notify player their songs are loaded
    printf("\nSongs loaded from file.\n");

    // Close and flush the file
    fclose(playlistFile);
    fflush(playlistFile);
}

/*
*	Description: Writes in values to a file from a list.
*	Date: 1/26/2024
*
*	Preconditions: Actual arguments are valid, file has been opened.
*	Postconditions: The file has been written to.
*/
void storeRecords(Node* pStart)
{
	// Declare required variables
	Node* pCurrent = pStart;
    FILE* playlistFile = fopen("musicPlayList.csv", "w");

    // Check the file opened successfully
    if (playlistFile == NULL)
    {
        printf("\nError opening file.\n");
        return;
    }

    // Notify user if there are no songs to display
    if (pCurrent == NULL)
    {
        printf("\nThere are no songs to store!\n");
    }
    else
    {
        // Keep going while a node still exists in the playlist
        while (pCurrent != NULL)
        {
            // Find out if the artist has a first and last name and print accordingly
            if (strchr(pCurrent->recordData.artist, ' ') != NULL)
            {
                fprintf(playlistFile, "\"%s\",%s,%s,%s,%02d:%02d,%d,%d\n", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                    pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                    pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
            }
            else
            {
                fprintf(playlistFile, "%s,%s,%s,%s,%02d:%02d,%d,%d\n", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                    pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                    pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
            }

            // Increment pCurrent
            pCurrent = pCurrent->pNext;
        }

        // Notify player their songs are stored
        printf("\nSongs stored to file.\n");
    }

    // Close and flush the file
    fclose(playlistFile);
    fflush(playlistFile);
}

/*
*	Description: Writes in values to a file from a list.
*	Date: 1/26/2024
*
*	Preconditions: Actual arguments are valid, printSpecificRecord is 0 for print all records, and 1 for print specific record.
*	Postconditions: The file has been written to.
*/
void displayRecords(Node* pStart, int printSpecificRecord, char artistName[])
{
    // Declare required variables
    Node* pCurrent = pStart;
    int foundARecord = 0;

    // Notify user if there are no songs to display
    if (pCurrent == NULL)
    {
        printf("\nThere are no songs to display!");
    }
    else
    {
        // Keep going while a node still exists in the playlist
        while (pCurrent != NULL)
        {
            // Print a specific artist or all songs
            if (printSpecificRecord == 0)
            {
                // Find out if the artist has a first and last name and print accordingly
                if (strchr(pCurrent->recordData.artist, ' ') != NULL)
                {
                    printf("\n\"%s\",%s,%s,%s,%02d:%02d,%d,%d", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                        pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                        pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
                }
                else
                {
                    printf("\n%s,%s,%s,%s,%02d:%02d,%d,%d", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                        pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                        pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
                }
            }
            else if (printSpecificRecord == 1)
            {
                // Remove the trailing newline character
                artistName[strlen(artistName) - 1] = '\0';

                // Print record if it matches the specified name
                if (strcmp(pCurrent->recordData.artist, artistName) == 0)
                {
                    // Find out if the artist has a first and last name and print accordingly
                    if (strchr(pCurrent->recordData.artist, ' ') != NULL)
                    {
                        printf("\n\"%s\",%s,%s,%s,%02d:%02d,%d,%d", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                            pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                            pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
                    }
                    else
                    {
                        printf("\n%s,%s,%s,%s,%02d:%02d,%d,%d", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                            pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                            pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
                    }

                    // Let program know a song was printed out
                    foundARecord = 1;
                }
            }

            // Increment pCurrent
            pCurrent = pCurrent->pNext;
        }

        // If no songs from the artist filter were printed, print a message
        if (foundARecord == 0 && printSpecificRecord == 1)
        {
            printf("\nThere were no songs found by that artist!");
        }
    }

    // Add a line break at the end of the list
    printf("\n");
}

/*
*	Description: Rates a record, giving it a new rating.
*	Date: 1/26/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The record has a new rating.
*/
void rateRecord(Node* pStart, char recordName[], int newRating)
{
    // Declare required variables
    Node* pCurrent = pStart;
    int foundARecord = 0;

    // Ensure the new rating is between 1 and 5
    if (newRating > 5)
    {
        newRating = 5;
    }
    else if (newRating < 1)
    {
        newRating = 1;
    }

    // Notify user if there are no songs to display
    if (pCurrent == NULL)
    {
        printf("\nThere are no songs to display!\n");
    }
    else
    {
        // Keep going while a node still exists in the playlist
        while (pCurrent != NULL)
        {
            // Remove the trailing newline character
            recordName[strlen(recordName) - 1] = '\0';

            // Print record if it matches the specified name
            if (strcmp(pCurrent->recordData.songTitle, recordName) == 0)
            {
                // Set the record's rating
                pCurrent->recordData.rating = newRating;

                // Let user know rating was updated
                printf("\nRating for \"%s\" has been updated to %d!\n", recordName, newRating);

                // Let program know a song was printed out
                foundARecord = 1;
            }

            // Increment pCurrent
            pCurrent = pCurrent->pNext;
        }

        // If no songs from the artist filter were printed, print a message
        if (foundARecord == 0)
        {
            printf("\nThere were no songs found by that song title!\n");
        }
    }
}

/*
*	Description: Edits a record, allowing all fields to be edited.
*	Date: 1/29/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The record has new values.
*/
void editRecord(Node* pStart, char recordName[], char lineOfData[])
{
    // Declare required variables
    Node* pCurrent = pStart;
    int foundARecord = 0;
    char* token = NULL;

    // Notify user if there are no songs to edit
    if (pCurrent == NULL)
    {
        printf("\nThere are no songs to edit!\n");
    }
    else
    {
        // Keep going while a node still exists in the playlist
        while (pCurrent != NULL)
        {
            // Remove the trailing newline character
            recordName[strlen(recordName) - 1] = '\0';

            // Print record if it matches the specified name
            if (strcmp(pCurrent->recordData.songTitle, recordName) == 0)
            {
                // Set the record's artist
                // Check if the artist name is enclosed in double quotes
                if (lineOfData[0] == '"')
                {
                    // Get data until the second quote
                    token = strtok(lineOfData, "\"");

                    // Copy the artist
                    strcpy(pCurrent->recordData.artist, token);
                }
                else
                {
                    // Get the artist
                    token = strtok(lineOfData, ",");

                    // Copy the artist
                    strcpy(pCurrent->recordData.artist, token);
                }

                // Continue reading other fields
                token = strtok(NULL, ",");
                strcpy(pCurrent->recordData.albumTitle, token);

                token = strtok(NULL, ",");
                strcpy(pCurrent->recordData.songTitle, token);

                token = strtok(NULL, ",");
                strcpy(pCurrent->recordData.genre, token);

                token = strtok(NULL, ":");
                pCurrent->recordData.songLength.minutes = atoi(token);

                token = strtok(NULL, ",");
                pCurrent->recordData.songLength.seconds = atoi(token);

                token = strtok(NULL, ",");
                pCurrent->recordData.numberTimesPlayed = atoi(token);

                token = strtok(NULL, ",");
                pCurrent->recordData.rating = atoi(token);

                // Let user know record was updated
                printf("\nRecord has been successfully edited!\n");

                // Let program know a song was printed out
                foundARecord = 1;
            }

            // Increment pCurrent
            pCurrent = pCurrent->pNext;
        }

        // If no songs from the artist filter were printed, print a message
        if (foundARecord == 0)
        {
            printf("\nThere were no songs found by that song title!\n");
        }
    }
}

/*
*	Description: Plays the playlist, starting from the selected song, and going until the end.
*	Date: 1/29/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: The playlist is played until the end.
*/
void playPlaylist(Node* pStart, char recordName[])
{
    // Declare required variables
    Node* pCurrent = pStart;
    int foundARecord = 0;
    char* token = NULL;

    // Notify user if there are no songs to play
    if (pCurrent == NULL)
    {
        printf("\nThere are no songs to play!\n");
    }
    else
    {
        // Keep going while a node still exists in the playlist
        while (pCurrent != NULL)
        {
            // Remove the trailing newline character
            // Code adapted from a previous TA in the WSU CS Discord
            char* character = strchr(recordName, '\n');
            if (character != NULL)
            {
                *character = '\0';
            }

            // Print record if it matches the specified name
            if (strcmp(pCurrent->recordData.songTitle, recordName) == 0 && foundARecord == 0)
            {
                // Clear the screen
                system("cls");

                // Find out if the artist has a first and last name and print accordingly
                if (strchr(pCurrent->recordData.artist, ' ') != NULL)
                {
                    printf("\"%s\",%s,%s,%s,%02d:%02d,%d,%d", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                        pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                        pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
                }
                else
                {
                    printf("%s,%s,%s,%s,%02d:%02d,%d,%d\n", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                        pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                        pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
                }

                // Let program know a song was printed out
                foundARecord = 1;

                // Make the program delay and clear the screen
                Sleep(3000);
                system("cls");
            }
            else if (foundARecord == 1)
            {
                // Find out if the artist has a first and last name and print accordingly
                if (strchr(pCurrent->recordData.artist, ' ') != NULL)
                {
                    printf("\"%s\",%s,%s,%s,%02d:%02d,%d,%d\n", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                        pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                        pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
                }
                else
                {
                    printf("%s,%s,%s,%s,%02d:%02d,%d,%d\n", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                        pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                        pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
                }

                // Make the program delay and clear the screen
                Sleep(3000);
                system("cls");
            }

            // Increment pCurrent
            pCurrent = pCurrent->pNext;
        }

        // If no songs from the artist filter were printed, print a message
        if (foundARecord == 0)
        {
            printf("\nThere were no songs found by that song title!\n");
        }
    }
}

/*
*	Description: Gets details for a new record and inserts it as a node at the front of the list.
*	Date: 2/1/2024
*
*	Preconditions: None.
*	Postconditions: A new node with the given information is inserted.
*/
void insertRecord(Node **pStart, char lineOfData[])
{
    Record newRecord;
    char* token = NULL;

    // Set the record's artist
    // Check if the artist name is enclosed in double quotes
    if (lineOfData[0] == '"')
    {
        // Get data until the second quote
        token = strtok(lineOfData, "\"");

        // Copy the artist
        strcpy(newRecord.artist, token);
    }
    else
    {
        // Get the artist
        token = strtok(lineOfData, ",");

        // Copy the artist
        strcpy(newRecord.artist, token);
    }

    // Continue reading other fields
    token = strtok(NULL, ",");
    strcpy(newRecord.albumTitle, token);

    token = strtok(NULL, ",");
    strcpy(newRecord.songTitle, token);

    token = strtok(NULL, ",");
    strcpy(newRecord.genre, token);

    token = strtok(NULL, ":");
    newRecord.songLength.minutes = atoi(token);

    token = strtok(NULL, ",");
    newRecord.songLength.seconds = atoi(token);

    token = strtok(NULL, ",");
    newRecord.numberTimesPlayed = atoi(token);

    token = strtok(NULL, ",");
    newRecord.rating = atoi(token);

    // Insert the new node into the list
    insertFront(pStart, newRecord);

    // Let user know rating was updated
    printf("\nRecord has been successfully created and inserted!\n");
}

/*
*	Description: Gets details for a new record and inserts it as a node at the front of the list.
*	Date: 2/1/2024
*
*	Preconditions: Actual arguments are valid.
*	Postconditions: A new node with the given information is inserted.
*/
void deleteRecord(Node** pStart, char recordName[])
{
    Node* pCurrent = *pStart, * pPrev = NULL, * pNext = NULL;
    int foundARecord = 0;

    // Notify user if there are no songs to delete
    if (pCurrent == NULL)
    {
        printf("\nThere are no songs to delete!\n");
    }
    else
    {
        // Keep going while a node still exists in the playlist
        while (foundARecord == 0 && pCurrent != NULL)
        {
            // Remove the trailing newline character
            if (recordName[strlen(recordName) - 1] == '\n')
            {
                recordName[strlen(recordName) - 1] = '\0';
            }

            // Print record if it matches the specified name
            if (foundARecord == 0 && strcmp(pCurrent->recordData.songTitle, recordName) == 0)
            {
                // Update pointers for deallocation
                pPrev = pCurrent->pPrev;
                pNext = pCurrent->pNext;

                // Delete the record and free it's memory
                if (pPrev == NULL)
                {
                    // Deleting the first element in the list
                    *pStart = pNext;

                    if (pNext != NULL)
                    {
                        pNext->pPrev = NULL;
                    }
                }
                else
                {
                    // Deleting other elements in the list
                    pPrev->pNext = pNext;

                    if (pNext != NULL)
                    {
                        pNext->pPrev = pPrev;
                    }
                }

                // Deallocate the node and avoid dangling pointer
                free(pCurrent);

                // Let program know a song was printed out
                foundARecord = 1;

                // Let user song was deleted
                printf("\n\"%s\" was successfully deleted!\n", recordName);
            }

            // Increment pointers
            if (foundARecord == 0)
            {
                pCurrent = pCurrent->pNext;
            }
        }

        // If no songs from the artist filter were printed, print a message
        if (foundARecord == 0)
        {
            printf("\nThere were no songs found by that song title!\n");
        }
    }
}

/*
*	Description: This function swaps 2 record's data.
*	Date: 2/6/2024
*
*	Preconditions: All actual arguments are valid.
*	Postconditions: The records have been swapped.
*/
void swapRecords(Node* firstRecord, Node* secondRecord)
{
    Record tempRecord = firstRecord->recordData;
    firstRecord->recordData = secondRecord->recordData;
    secondRecord->recordData = tempRecord;
}

/*
*	Description: This function will sort the playlist a certain way, depending on the user's input.
*	Date: 2/6/2024
*
*	Preconditions: All actual arguments are valid.
*	Postconditions: The playlist has been sorted by user's specified mode.
*/
void sortPlaylist(Node** pStart, int sortMode)
{
    Node* pCurrent = *pStart, * pNext = pCurrent->pNext, * pLastSorted = NULL;
    int isSorted = 0;

    // Notify user if there are no songs to sort
    if (pCurrent == NULL)
    {
        printf("\nThere are no songs to sort!\n");
    }
    else
    {
        // Keep going while the list isn't sorted
        while (isSorted == 0)
        {
            // Update the variables
            pCurrent = *pStart;
            pNext = pCurrent->pNext;

            // Update isSorted to show list is sorted
            isSorted = 1;

            // Keep going while a node still exists in the playlist
            while (pCurrent != NULL && pNext != NULL)
            {
                // Perform a sort depending on the current selected mode
                switch (sortMode)
                {
                case 1:
                    // Sort based on artist (A - Z)
                    if (pNext != NULL && strcmp(pCurrent->recordData.artist, pNext->recordData.artist) > 0)
                    {
                        swapRecords(pCurrent, pNext);
                        isSorted = 0;
                    }
                    break;
                case 2:
                    // Sort based on album (A - Z)
                    if (pNext != NULL && strcmp(pCurrent->recordData.albumTitle, pNext->recordData.albumTitle) > 0)
                    {
                        swapRecords(pCurrent, pNext);
                        isSorted = 0;
                    }
                    break;
                case 3:
                    // Sort based on rating (1 - 5)
                    if (pNext != NULL && pCurrent->recordData.rating > pNext->recordData.rating)
                    {
                        swapRecords(pCurrent, pNext);
                        isSorted = 0;
                    }
                    break;
                case 4:
                    // Sort based on times played (0 - inf)
                    if (pNext != NULL && pCurrent->recordData.numberTimesPlayed > pNext->recordData.numberTimesPlayed)
                    {
                        swapRecords(pCurrent, pNext);
                        isSorted = 0;
                    }
                    break;
                default:
                    break;
                }

                // Update the variables
                pCurrent = pNext;
                if (pNext != NULL)
                {
                    pNext = pNext->pNext;
                }

                // Debugging statements should be placed here
                printf("Comparing %s with %s\n", pCurrent->recordData.artist, pNext->recordData.artist);

                // If a swap occurred, set isSorted to 0
                if (!isSorted) {
                    isSorted = 0;
                }
            }

            // Update the pLastSorted variable
            pLastSorted = pCurrent;
        }
    }
}

/*
*	Description: The function will determine a random order for songs to be played.
*	Date: 2/8/2024
*
*	Preconditions: All acutal arguments are valid.
*	Postconditions: The playlist is randomly shuffled and played until all songs have played.
*/
void shufflePlaylist(Node* pStart)
{
    // Count the number of songs in the playlist, since we don't know this
    int numberOfSongs = 0;
    Node* pCurrent = pStart;
    int* playOrderArray = NULL;

    while (pCurrent != NULL)
    {
        numberOfSongs++;
        pCurrent = pCurrent->pNext;
    }

    if (numberOfSongs == 0)
    {
        printf("\nThere are no songs to shuffle!\n");
    }
    else
    {
        // Allocate memory for the array
        playOrderArray = (int*)malloc(numberOfSongs * sizeof(int));

        if (playOrderArray != NULL)
        {
            // Initialize the play array with zeros
            for (int i = 0; i < numberOfSongs; i++)
            {
                playOrderArray[i] = 0;
            }

            // Populate the play array with random indices
            srand(time(NULL));

            for (int i = 1; i <= numberOfSongs; i++)
            {
                int playOrder;

                // Populates a random index with a random, if it's not already assigned
                do
                {
                    // Generate a random number between 0 and numberOfSongs - 1
                    playOrder = rand() % numberOfSongs;
                } while (playOrderArray[playOrder] != 0);

                // Assign the index representing the position of the song
                playOrderArray[playOrder] = i;
            }

            // Set the variables
            pCurrent = pStart;

            // Play all songs from the beginning based on new order
            for (int i = 0; i < numberOfSongs; i++) {
                playSongAtIndex(pStart, playOrderArray, i);
            }
        }
        else
        {
            printf("\nMemory allocation failed!\n");
        }
    }
}

/*
*	Description: The function will determine a manual order for songs to be played.
*	Date: 2/8/2024
*
*	Preconditions: All acutal arguments are valid.
*	Postconditions: The playlist is manually shuffled and played until all songs have played.
*/
void shufflePlaylistManual(Node* pStart, int* playOrderArray)
{
    Node* pCurrent = pStart;

    if (pStart == NULL)
    {
        printf("\nThere are no songs to shuffle!\n");
    }
    else
    {
        // Play all songs from the beginning based on new order
        for (int i = 0; i < 3; i++) {
            playSongAtIndex(pStart, playOrderArray, i);
        }
    }
}

/*
*	Description: This function traverses the linked list and finds the correct song, and plays it.
*	Date: 2/8/2024
*
*	Preconditions: All actual arguments are valid.
*	Postconditions: A song is played.
*/
void playSongAtIndex(Node* pStart, int* playOrder, int index)
{
    // Traverse the playlist to find the song at the specified index
    Node* pCurrent = pStart;
    int i = 1, playlistIndex = playOrder[index];

    // Find the correct song to play
    while (pCurrent != NULL && i < playlistIndex)
    {
        pCurrent = pCurrent->pNext;
        i++;
    }

    // If a song exists, this check isn't neccessary, but good to have
    if (pCurrent != NULL)
    {
        // Clear the screen
        system("cls");

        // Find out if the artist has a first and last name and print accordingly
        if (strchr(pCurrent->recordData.artist, ' ') != NULL)
        {
            printf("\"%s\",%s,%s,%s,%02d:%02d,%d,%d\n", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
        }
        else
        {
            printf("%s,%s,%s,%s,%02d:%02d,%d,%d\n", pCurrent->recordData.artist, pCurrent->recordData.albumTitle,
                pCurrent->recordData.songTitle, pCurrent->recordData.genre, pCurrent->recordData.songLength.minutes,
                pCurrent->recordData.songLength.seconds, pCurrent->recordData.numberTimesPlayed, pCurrent->recordData.rating);
        }

        // Delay and clear the screen
        Sleep(3000);
    }
}