/*Title: Chapter 8 Quiz
Author: Ian Breckenridge
Date: 21 November 2017
Description: */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void intro(void);                       // function to display the introduction to the user

int main()
{
	ifstream inDessert;		//file stream for the desserts
	ifstream inCalories;	//file stream for the calories
	ifstream inCount;		//file stream for the orders
	string   dessert[7];    //array for the dessert names
	string dessert_name;	//variable to store dessert names
	double high = 0;		//finds greatest number
	double low = 0;
	double calories[7];	//array for the calories
	double orders[7];	//array for the orders
	int row;				//indexes
	int i = 0;				
	int j = 6;
	int k = 6;
	int loop;
	char wait;				//keeps program from automatically closing

	intro();

	//Open the Dessert file
	inDessert.open("Dessert.dat");
	if (!inDessert)
	{
		cout << "Error opening Dessert File - Dessert.dat\n";
		return 0;
	}

	//Open the Calories file
	inCalories.open("Calories.dat");
	if (!inCalories)
	{
		cout << "Error opening Dimensions File - Calories.dat\n";
		inCalories.close();
		return 0;
	}

	//Open the Orders file
	inCount.open("Count.dat");
	if (!inCalories)
	{
		cout << "Error opening Dimensions File - Count.dat\n";
		inCount.close();
		return 0;
	}
	//Read the data into the arrays
	row = 0;
	while (!inDessert.eof())
	{
		//read the dessert name
		getline(inDessert, dessert_name); //Gets a single line from example.txt
		dessert[row] = dessert_name; //Saves that line in the array

		//read the calories and orders
		inCalories >> calories[row];
		inCount >> orders[row];

		//post-increment counter
		row++;
	}
	cout << "Dessert" << "               " << "Calories" << "               " << "Number of Orders" << "\n\n";
	for (loop = 0; loop < row; loop++) //For loop make to cout the lines stored
		cout << dessert[loop] << "      " << calories[loop] << "                    " << orders[loop] << "\n\n";

	high = orders[0];
	for (int k = 1; k <= 7; k++)
	{
		if (orders[k] > high)
		{
			high = orders[k];
		}
	}
	cout << "The dessert with the greatest amount of orders is: \n" << dessert[k] << "   " << calories[k] << "   " << orders[k] << "\n";

	high = calories[0];
	for (int i = 1; i <= 7; i++)
	{
		if (calories[i] > high)
			high = calories[i];
	}
	cout << "The dessert with the greatest amount of calories is: \n" << dessert[i] << "   " << calories[i] << "   " << orders[i] << "\n";
	low = calories[0];
	for (int j = 1; j <= 7; j++)
	{
		if (calories[j] < low)
			low = calories[j];
	}
	cout << "The dessert with the fewest amount of calories is: \n" << dessert[j] << "   " << calories[j] << "   " << orders[j] << "\n";


	cout << "Press any key to continue... "; cin >> wait;
	return 0;
}

/* Title: intro
// Author: Ian Breckenridge
// Date: 21 November 2017
Description: Introduces program to userThis function provides an introduction for the user to the program.*/
void intro(void)
{
	cout << "Welcome to \"Data Reader\", a program that reads three files containing: dessert names, \n "
		<< "calories, and number of orders. It then sorts the information by column, and displays the \n"
		<< "data to the user along with the most frequently ordered dessert, the dessert with the largest \n"
		<< "number of calories, and the dessert with the lowest number of calories.\n\n";
}
