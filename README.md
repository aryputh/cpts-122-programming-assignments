## CptS 122 - Programming Assignments
This repository includes all of my programming assignments for the CptS 122 course taken in college.

### Programming Assignment 1
In this assignment, I analyzed data generated from a fitness device stored in a .csv file.<br><br>

My tasks included filtering data for the target patient, deduping entries, and data cleansing. I defined a C struct to store Fitbit data and an array to hold 24 hours of minute data. The program didn't require user input but instead displayed results.<br><br>

I computed total calories, distance walked, floors climbed, and steps taken, along with the average heart rate. Additionally, I reported the max steps taken in one minute and the longest consecutive range of poor sleep. Output was written to _Results.csv_ and displayed on the screen, including summary statistics and details of the analyzed data.

### Programming Assignment 2 and 3
For this assignment, I developed a basic digital music manager (DMM) with a text-based interface. Options include: loading, storing, displaying, editing, rating, playing, shuffling, and exiting.<br>
- _Load_ reads records from a file called musicPlayList.csv into a dynamic doubly linked list of records, each record containing attributes like artist, album title, song title, genre, song length, number of times played, and rating.
- _Store_ writes the current records to musicPlayList.csv.
- _Display_ prints all records or those matching an artist.
- _Edit_ allows the modifying of attributes of a record.
- _Rate_ allows assigning a 1-5 rating to a song.
- _Play_ starts playing each song in order, displaying record contents for a short period.
- _Exit_ saves the most recent list to musicPlayList.csv, overwriting previous contents.

### Programming Assignment 4
For this C++ fitness application, I created three classes: DietPlan, ExercisePlan, and FitnessAppWrapper.<br><br>

The DietPlan class represents a daily diet plan with attributes for goal calories, plan name, and date. Similarly, the ExercisePlan class represents a daily exercise plan with attributes for goal steps, plan name, and date. Both classes provide member functions including constructors, copy constructors, destructors, and an editGoal() function to modify the plan's goal. Overloaded stream insertion (<<) and extraction (>>) operators for both displaying and writing plans to files were also created.<br><br>

Daily plans are read from files named _dietPlans.txt_ and _exercisePlans.txt_. Each file contains seven daily plans for a full week, with each plan represented by plan name, goal, and date.<br><br>

The FitnessAppWrapper class manages the application, containing two lists of weekly plans (diet and exercise). It provides member functions such as _runApp()_, _loadDailyPlan()_, _loadWeeklyPlan()_, _displayDailyPlan()_, _displayWeeklyPlan()_, _storeDailyPlan()_, _storeWeeklyPlan()_, and _displayMenu()_, all of which are accessible to the user. The _displayMenu()_ function presents the 9 options including loading and storing weekly plans, displaying plans to the screen, editing daily plans, and exiting the application, which saves the most recent weekly plans to corresponding files.

### Programming Assignment 5
Coming Soon!

### Programming Assignment 6
Coming Soon!

### Programming Assignment 7
Coming Soon!

### Programming Assignment 8
Coming Soon!

### Programming Assignment 9
This programming assignment was to create a game using C++ that demonstrated our knowledge of inheritence, classes, abstraction, and more.<br><br>
This PA isn't included in this repository, but you can find it [here](https://github.com/aryputh/cpts-122-final). We decided to use Unreal Engine and to form a simple treasure hunt game.
