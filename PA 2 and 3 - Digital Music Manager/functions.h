/*
	Aryan Puthran
	Class: CptS 122, Spring 2024
	Lab Section: 06
	Assignment: Programming Assignment 2
	Date: 1/25/2024
	Description: This program uses a doubly linked list to keep track of a playlist. In addition, the
		program can perform functions on the playlist.
*/

// Preprocessor directives
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// Struct definitions
typedef struct duration
{
	int minutes;
	int seconds;
} Duration;

typedef struct record
{
	char artist[50];
	char albumTitle[50];
	char songTitle[50];
	char genre[30];
	Duration songLength;
	int numberTimesPlayed;
	int rating;
} Record;

typedef struct node
{
	Record recordData;
	struct Node* pNext;
	struct Node* pPrev;
} Node;

// Function prototypes
Node* createNode(Record* recordData);
int insertFront(Node** pStart, Record newRecord);
void clearList(Node** pStart);
void loadRecords(Node** pStart);
void storeRecords(Node* pStart);
void displayRecords(Node* pStart, int printSpecificRecord, char artistName[]);
void rateRecord(Node* pStart, char recordName[], int newRating);
void editRecord(Node* pStart, char recordName[], char lineOfData[]);
void playPlaylist(Node* pStart, char recordName[]);
void insertRecord(Node** pStart, char lineOfData[]);
void deleteRecord(Node** pStart, char recordName[]);
void swapRecords(Node* firstRecord, Node* secondRecord);
void sortPlaylist(Node** pStart, int sortMode);
void shufflePlaylist(Node* pStart);
void shufflePlaylistManual(Node* pStart, int* playOrderArray);
void playSongAtIndex(Node* pStart, int* playOrder, int index);