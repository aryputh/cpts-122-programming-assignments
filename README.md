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
For this simulation assignment, I created two queues representing an express lane and a normal lane. Each queue node contains customer information such as customer number, service time, and total time. The program generates random arrival times and service times for customers in each lane.<br><br>

The simulation runs for a user-provided number of minutes. Customers arrive every _1-5_ minutes in the express lane and every _3-8_ minutes in the normal lane. Service times vary from _1-5_ minutes for express lane customers and _3-8_ minutes for normal lane customers.<br><br>

During the simulation, messages are printed indicating customer arrival, service, and total time in each lane. Every 10 minutes, the entire queue for each lane is printed.<br><br>

I also implemented test cases using a separate test class to test _enqueue()_ and _dequeue()_ operations on the queues and a test case to run the simulation for 24 hours.

### Programming Assignment 6
In this assignment, I used a Binary Search Tree (BST) to convert English characters to Morse code strings.<br><br>

I started by designing the _BSTNode_ class, which had a character and a string as members. The character held the English text character and the string held the corresponding Morse code. I also created a constructor to set the English text character and Morse code string.<br><br>

I then read in the Morse table from a file called _MorseTable.txt_ (which contained a map I made to ensure a balanced tree was made). I built the tree in the constructor of the BST by creating nodes for each character and inserting them into the tree. I implemented a _print()_ function using recursion to traverse the tree in order and a _search()_ function to return the Morse code string for each English character. I also created a destructor that recursively destroys the tree.

### Programming Assignment 7
In this assignment, I created an application that tracks attendance. There were 4 main requirements:
1. The application must import records from a course list stored in a comma-separated values (.csv) file. Each record consists of fields such as record number, ID number, name, email, units, program, and standing. The records are inserted into a singly linked list with a custom stack data structure for tracking absences.
2. The application allows the user to mark each student as present or absent for the current day. The date is derived from the computer's system date, and absences are stored in a stack within each student's record.
3. The application generates two versions of reports. The first version shows all students in the class along with the number of absences and the date of the most recent absence. The second version provides only the names of students absent for a number of times greater than a user-given number.
4. At startup, the application displays a menu with six options:
    - Import course list
    - Load master list
    - Store master list
    - Mark absences
    - Generate report
    - Exit application

Just like other PAs, the application keeps running until you choose to exit the app.

### Programming Assignment 8
Coming Soon!

### Programming Assignment 9
This programming assignment was to create a game using C++ that demonstrated our knowledge of inheritence, classes, abstraction, and more.<br><br>
This PA isn't included in this repository, but you can find it [here](https://github.com/aryputh/cpts-122-final). We decided to use Unreal Engine and to form a simple treasure hunt game.
