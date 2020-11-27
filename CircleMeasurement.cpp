/*Name: Circle Measurement Calculator
Author : Ian Breckenridge
Date : 21 September 2017
Description : The purpose of this program is to calculate the, radius, circumference or diameter
(depending on the input), and area of the cross section of the circle given EITHER the diameter
or circumference */

#include <iostream>
using namespace std;

int main()
{
	//Definitions and Declarations
	double diameter; //Diameter of circle entered by user
	double radius; //Radius of circle entered by user
	double circumference; //Circumference of circle entered by user
	double area_xsection; //Area of the cross section of circle entered by user
	double pi = 3.14; //Value of pi
	int value; //Variable that determines whether the first input from the user is the diameter or circumference
	char wait; //program closes automatically after numbers are input, this variable prevents this.

	//Introduce program to the user
	cout << "Welcome to Circle Calculator! \n";
	cout << "\nYou will be asked to provide the diameter or the circumference of the circle\n";
	cout << "and the program will display the resulting radius, circumference or diameter,\n";
	cout << "and the area of the cross section\n\n";
	
	//Input that will determine which variable (circumference or diameter) the user is inputing
	cout << "For your starting value, if you are entering the diameter, enter 0. ";
	cout << "\nIf you are entering the circumference, enter 1: ";
	cin >> value;

	//"if" statements that use logic to determine which variable the user is inputing
	if (value == 0) //For the diameter
	{
		// Get the diameter from the user
		cout << "\nPlease enter the diameter: ";
		cin >> diameter;

		//Calculations
		radius = diameter / 2; //Calculate radius
		circumference = diameter * pi; //Calculate circumference
		area_xsection = radius * radius * pi; //Calculate area of the cross section

		//Display results to the user
		cout << "\nGiven the diameter, " << diameter << ", the radius is " << radius;
		cout << ", the circumference is " << circumference << ", \nand the area of the cross section is ";
		cout << area_xsection << ".";

		//Return
		cout << "\n\nEnter any character and press enter to continue: ";
		cin >> wait;
		return 0;
	}

	if (value == 1) //For the circumference
	{
		//Get the circumference from the user
		cout << "Please enter the circumference: ";
		cin >> circumference;

		//Calculations
		diameter = circumference / pi; //Calculate diameter
		radius = diameter / 2; //Calculate the radius
		area_xsection = radius * radius * pi; //Calculate the area of the cross section

		//Display results to user
		cout << "\nGiven the circumference, " << circumference << ", the radius is " << radius;
		cout << ", the diameter is " << diameter << ", \nand the area of the cross section is " << area_xsection << ".";
		cout << "\n\nEnter any character and press enter to continue: ";
		cin >> wait;
		return 0;
	}

	else //Catch-all for other inputs (except characters which close the program)
	{
		//Error statement
		cout << "\nYou input an invalid argument.\n";
		//Return
		cout << "\nEnter any character and press enter to continue: ";
		cin >> wait;
		return 0;
	}
}


