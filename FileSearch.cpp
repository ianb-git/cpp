// Title: File Search
// Author: John Houston   Date: November 7, 2017
// It was debugged by: Ian Breckenridge
//
// Welcome to the quiz! Your job is to debug this program so that it will work correctly and be 
// properly commented. The program is intended to ask the user for the first name of a member of 
// your class, and generate a message corresponding to that student. Be very cautious! The answers 
// from your program will not necessarily match those of your classmates.
// Hint: There are: 
//       4 bugs that prevent it from working correctly, 
//       1 bug makes things not display correctly,
//       and a variety of places that require comments.

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

// Functions used to operate this program
void intro(void);
int findName(string filename, string student);  // will return the line number in the given input file
void readLineFromFile(int row, string&message); // reads a specific line from the message file
void shiftNameFile(int row);                    // modifies the input file to personalize it

int main()
{
	bool keep_going = true;       // boolean operator that determines whether user wants to continue through input
	int number_of_passes = 0;     // counting integer that determines number of passes of program through while loop
	int row;                      // row number in the file
	char response = 'n';          // sentinel 
	string name;                  // first name of classmate
	string message;               // message to display
	string yourName = "Ian";   // your first name
	char keep_open; //prevents program from closing automatically after variables are input
	
	// introduction to the user
	intro(); //introduces program to user

	// DO NOT CHANGE THE FOLLOWING 3 LINES!!!
	// scramble the student list                // DO NOT CHANGE THIS
	row = findName("basefile.dat", yourName);   // DO NOT CHANGE THIS
	shiftNameFile(row);                         // DO NOT CHANGE THIS

	// while loop that makes program wait until the user is ready to begin
	while ((response != 'y') && (response != 'Y'))
	{
		// Ask the user if they are ready to begin
		cout << "Are you ready to begin? (Please enter y for yes, n for no) ";
		cin >> response;
		cout << endl;
	}

	// Keep going until the user indicates they want to stop
	while (keep_going)
	{
		// ask the user for name they wish to find
		cout << "Please enter the name you wish to find: ";
		cin >> name;
		cout << endl << endl;

		// find the line in the name file containing the name user selected
		row = findName("basefile.dat", name);

		// handle any errors from the name file
		if (row == -1)
			continue;

		// use that number as the line number into another input file
		readLineFromFile(row % 6, message); /*Since there are only 6 unique messages, mod 6 prevents program from returning 
											a blank output to the user */

		// print the line found at that location
		cout << "The message for " << name << " is: " << message << endl << endl;

		// count the number of complete passes through the loop
		number_of_passes++;

		// ask the user if they want to continue
		cout << "Do you wish to continue? If so, please enter 'y' or 'Y' ";
		cin >> response;
		cout << endl;
		if ((response != 'y') && (response != 'Y'))
			keep_going = false;
	}

	// display message to the user
	cout << "The program completed " << number_of_passes << " searches." << endl
		<< "Thank you for using the program. Come back again!" << endl << endl;

	// Close program
	cout << "Enter any character and press enter to continue... ";
	cin >> keep_open; //Prevents program from closing automatically
	return 0;
}

// Author: John Houston
// Created: November 5, 2017
// Intro: This is a function to display a message to the user about this program. 
void intro()
{
	cout << "Welcome to 'File Search', a program that will search through a set of files " << endl
		<< "in a systematic way to find the answer to a mystery. Your assignment is to " << endl
		<< "fix the program to make it work correctly. In the end, the program is intended " << endl;
	cout << "to display a specific entry from an input file. Your answer may not match that " << endl;
	cout << "of others in the class!" << endl << endl;
}

// Author: John Houston
// Created: November 5, 2017
// findName: This function opens a file named "students.dat" and determines which row in the file
//           the name provided appears on. It returns that line number to the caller. If there is a 
//           problem, the function returns -1.
int findName(string fileName, string matchVal)
{
	const int MAX_STUDENTS = 10; // number of students in the class
	ifstream inData;             // input data stream
	int lineNumber;              // index
	string inputString;          // used to hold data read from file

								 // open the file
	inData.open(fileName);

	// report any problem opening the file
	if (!inData)
	{
		cout << "Error opening the input file '" << fileName << "'. Stopping execution." << endl << endl;
		return -1;
	}

	// read the lines in the file until we find a match for the name
	for (lineNumber = 0; lineNumber < MAX_STUDENTS; lineNumber++)
	{
		//read the next line of the file 
		getline(inData, inputString);

		// compare the matchVal to inputString
		if (matchVal == inputString)
			break;
	}

	// close the file
	inData.close();

	// check for student name not found, and handle the error
	if (lineNumber >= MAX_STUDENTS)
	{
		cout << "Student name not found in the file." << endl;
		return -1;
	}

	// otherwise, return the appropriate line number where the match was found
	else
		return lineNumber;
}

// Author: John Houston
// Created: November 5, 2017
// readLineFromFile: This function opens a file named "messages.dat", reads the selected messages,
// and returns that message to the caller.
void readLineFromFile(int lineNumber, string& message)
{
	int line = 0;
	ifstream msgFile;

	// open the message file
	msgFile.open("messages.dat");

	// read lines until we get to the intended message
	for (line; line <= lineNumber; line++)
	{
		getline(msgFile, message); /*once we get intended message, string 'message' is set to the message, and the loop ends
								   once the program exceeds lineNumber */
	}

	msgFile.close(); //closes file
}

// DO NOT CHANGE THIS FUNCTION!!!!   DO NOT CHANGE THIS FUNCTION!!!!   DO NOT CHANGE THIS FUNCTION!!!!

// Author: John Houston
// Created: November 5, 2017
// shiftNameFile: This function opens a file named "basefile.dat", reads until it finds the correct line
// then begins copying the rest of the file to a new file. It then goes back to the top of the 
// input file and continues to copy. 
void shiftNameFile(int lineNumber)
{
	int line = 0;      // index for file
	ifstream rawFile;  // input file
	ofstream newFile;  // output file
	string name;       // transfer variable

					   // open the original input file
	rawFile.open("basefile.dat");

	// read lines until we get to the intended message
	do
	{
		getline(rawFile, name);
	} while (line++ != lineNumber);

	// open the output file
	newFile.open("students.dat");

	// read the rest of the input file and write entries to the output file
	while (!rawFile.eof())
	{
		getline(rawFile, name);
		newFile << name << endl;
	}

	// if we did not start with the first name
	if (lineNumber)
	{
		// close the input file
		rawFile.close();

		// open the input file
		rawFile.open("basefile.dat");

		// copy the rest of the input file to the output file
		for (line = 0; line <= lineNumber; line++)
		{
			getline(rawFile, name);
			newFile << name << endl;
		}
	}

	// close both files
	rawFile.close();
	newFile.close();
}