/*Name: PA CH8
Author: Ian Breckenridge
Date: 16 November 2017
Description: */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void intro();
int main()
{
	// Definitions and Declarations
	ifstream infile;
	string fileName;
	string fileName2;
	ofstream outfile;
	string array[5][1]; //Array to save the line on
	int loop = 0; //Index of array
	int loop2;
	string line; //The line taken from the *.dat source
	//ifstream myfile(fileName.c_str()); //To read from the *.dat File
	char wait;

	// Introduce Program to User
	intro(); // intro function that introduces program to user

	// Get input data from user
	cout << "Please input the name of the file containing a list of shapes: "; cin >> fileName;

	infile.open(fileName.c_str());
	if (infile.is_open()) //Checking if the file can be opened
	{
		while (!infile.eof()) //Runs while the file is NOT at the end
		{
			getline(infile, line); //Gets a single line from example.txt
			array[loop][0] = line; //Saves that line in the array
			loop++; //Does an increment to the variable 'loop'
		}
		infile.close(); //Closes the file
	}
	else cout << "Unable to open file" << endl; //Gives that sentence if the file can't be opened
	loop = 0;
	cout << "Please input the name of the file containing numbers: "; cin >> fileName2;

	infile.open(fileName2.c_str());
	if (infile.is_open()) //Checking if the file can be opened
	{
		while (!infile.eof()) //Runs while the file is NOT at the end
		{
			getline(infile, line); //Gets a single line from example.txt
			array[loop][1] = line; //Saves that line in the array
			loop++; //Does an increment to the variable 'loop'
		}
		infile.close(); //Closes the file
	}
	else cout << "Unable to open file" << endl; //Gives that sentence if the file can't be opened
	sort(array, array + 5);
	for (loop2 = 0; loop2 <= loop; loop2++) //For loop make to cout the lines stored
		cout << array[loop2] << endl;    //inside of the variable 'array'
	/*outfile.open("Shapes.dat");
	outfile.open("Areas.dat");
	outfile.open("Perimeter.dat");*/

	// Return
	cout << "Input any character and press enter to continue... "; cin >> wait;
	return 0;
}


/*Function Name: Intro
Author: Ian Breckenridge
Date: November 5, 2017
Description: This is a function to display a message to the user about this program. */
void intro()
{
	cout << "Welcome to '', a program that will search through a set of files " << endl
		<< " in a systematic way to find the answer to a mystery. Your assignment is to " << endl
		<< " fix the program to make it work correctly. ";
		cout << "In the end, the program is intended to display a specific entry from an input " << endl
		<< " file. Your answer may not match that of others in the class!" << endl;
}

