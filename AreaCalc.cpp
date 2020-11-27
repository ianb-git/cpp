/*
Program Name: Area Calculator of 4 Different Shapes [Chapter 3/4 Quiz]
Author: Ian Breckenridge
Date: 03 October 2017
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Definitions and Declarations
	double c_radius; //radius of circle entered by user
	double c_area; //area of circle entered by user

	double sq_side; //side length of square entered by user
	double sq_area; //area of square entered by user

	double rec_l; //length of rectangle entered by user
	double rec_w; //width of rectangle entered by user
	double rec_area; //area of rectangle entered by user

	double tri_b; //length of base of triangle entered by user
	double tri_h; //height of triangle entered by user
	double tri_area; //area of triangle entered by user

	double pi = 3.141592654; //value of constant "pi", used to determine area of circle

	int which_shape_to_calculate; //Determines which shape the user intends to calculate the area of

	char wait; //Prevents program from automatically closing once values needed to be calculated are input

	cout << fixed << showpoint; //show output in fixed decimal format
	cout << setprecision(3); //sets precision of output to three decimal points

							 //Introduce program to user
	cout << "Hello, my name is Ian, I am the writer of this program. I am currently pursuing a Math degree\n";
	cout << "at DCC, and will be pursuing a Bachelors in Financial Mathematics at a four-year college,\n"; //Introducing myself
	cout << "and a graduate degree. In five years, I see myself in a risk analyst role in quantitative finance.\n\n";

	cout << "This program can calculate the area of a circle (using area = pi * radius^2, you will have to enter the radius),\n";
	cout << "a triangle (using area = (base * height) / 2, you will have to enter the base and the height),\n"; //Introducing program
	cout << "a rectangle (using area = length * width, you will have to enter the length and the width),\n";
	cout << "or a square (using area = side^2, you will have to enter the length of a side).\n\n";

	//Input that will determine which shape the user wants to calculate the area of
	cout << "If you want to calculate the area of a circle, type 1. \n";
	cout << "If you want to calculate the area of a triangle, type 2. \n";
	cout << "If you want to calculate the area of a rectangle, type 3. \n";
	cout << "If you want to calculate the area of a square, type 4. \n";

	cout << "\nPlease indicate your choice: ";
	cin >> which_shape_to_calculate;

	//"if" statements that use logic to determine shape the user wants to calulate the area of
	if (which_shape_to_calculate == 1) //Circle
	{
		//Get radius from user
		cout << "\nPlease enter the radius of the circle: ";
		cin >> c_radius;

		//Calculations
		c_area = pi * c_radius * c_radius;

		//Display results to user
		cout << "\nGiven the radius, " << c_radius << ", the area of the circle is " << c_area << ".\n\n";

		//Return
		cout << "Input any character and press enter to continue...";
		cin >> wait;
		return 0;
	}

	if (which_shape_to_calculate == 2) //Triangle
	{
		//Get base and height from user
		cout << "\nPlease enter the length of the base of the triangle: ";
		cin >> tri_b;
		cout << "\nPlease enter the height of the triangle: ";
		cin >> tri_h;

		//Calculations
		tri_area = (tri_b * tri_h) / 2;

		//Display results to user
		cout << "\nGiven the base length, " << tri_b << ", and the height, " << tri_h;
		cout << ", \nthe area of the triangle is " << tri_area << ".\n\n";

		//Return
		cout << "Input any character and press enter to continue...";
		cin >> wait;
		return 0;
	}

	if (which_shape_to_calculate == 3) //Rectangle
	{
		//Get length and width from user
		cout << "\nPlease enter the length of the rectangle: ";
		cin >> rec_l;
		cout << "\nPlease enter the width of the rectangle: ";
		cin >> rec_w;

		//Calculations
		rec_area = rec_l * rec_w;

		//Display results to user
		cout << "\nGiven the length, " << rec_l << ", and the width, " << rec_w;
		cout << ", \nthe area of the rectangle is " << rec_area << ".\n\n";

		//Return
		cout << "Input any character and press enter to continue...";
		cin >> wait;
		return 0;
	}

	if (which_shape_to_calculate == 4) //Square
	{
		//Get side length from user
		cout << "\nPlease enter the length of a side of the square: ";
		cin >> sq_side;

		//Calculations
		sq_area = sq_side * sq_side;

		//Display results to user
		cout << "\nGiven the side length, " << sq_side << ", the area of the square is " << sq_area << ".\n\n";

		//Return
		cout << "Input any character and press enter to continue...";
		cin >> wait;
		return 0;
	}

	else //Presents error statement for unrecognized inputs
	{
		//Error Statement
		cout << "\nError: You have entered an invalid character.\n";

		//Return
		cout << "Input any character and press enter to continue...";
		cin >> wait;
		return 0;
	}
}