/* Name: Derivative Calculator
Author: Ian Breckenridge
Date: 19 October 2017
Description: Derivative Calculator uses the limit definition of a derivative in a do...while loop to calculate the
instantaneous slope of a quadratic as "h" (or delta x) approaches 0*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//Definitions and Declarations
	double c1; //coefficient for "x^2" in quadratic equation, value determined by user
	double c2; //coefficient for "x" in quadratic equation, value determined by user
	double c3; //constant, value determined by user

	double x; //"x" value where quadratic equation is evaluated and derivative is taken, value determined by user

	double f_x; //variable where value of quadratic equation evaluated at "x" is stored
	double f_x_plus_h; //variable where value of quadratic equation evaluated at "x+h" is stored

	double test_tolerance = 0.001; //variable that is set to the value of derivative_f in the last iteration of the test
	double h = 0.1; /*let delta x = "h", this is the change in x, which is halved after each iteration of do...while loop
					to increase accuracy*/
	double derivative_f = 0.001; /*value of difference between f_x_plus_h and f_x divided by h (calculates slope as h -> 0),
								 derivative set to 0.001 so test_tolerance is not changed on first pass through do...while loop */
	int count = 0; //counts repetitions of do...while loop
	char wait; //Prevents program from automatically closing once values needed to be calculated are input

	//Introduce program to user
	cout << "Welcome to derivative calculator!\n\nYou will be asked";
	cout << " to provide the coefficients of the quadratic equation\n(of the form";
	cout << " c1 * x^2 + c2 * x + c3) and the value";
	cout << " for x at which the \nderivative is to be found.\n\n";
	
	//Get input data from user
	cout << "Please input a value for c1 (\"x^2\" coefficient): "; cin >> c1; cout << "\n";
	cout << "Please input a value for c2 (\"x\" coefficient): "; cin >> c2; cout << "\n";
	cout << "Please input a value for c3 (constant): "; cin >> c3; cout << "\n";
	cout << "Please input a value for x: ";  cin >> x; cout << "\n";

	//Sets value of quadratic equation "f_x" to be in used in do...while loop
	f_x = c1 * x * x + c2 * x + c3;

	//Do...while loop which calculates derivative of function based on repeated iterations
	do
	{
		test_tolerance = derivative_f; //sets test_tolerance equal to the previous derivative

		f_x_plus_h = c1 * (x + h) * (x + h) + c2 * (x + h) + c3; //Sets new value for f(x+h) based on change in h
		derivative_f = (f_x_plus_h - f_x) / h; //Calulates value of derivative for this iteration of test

		count++; //increments count variable by 1 to indicate the do...while loop was iterated

		h = h / 2; //halves h for next iteration to increase accuracy (essentially "taking the limit" by decreasing interval to approach 0)
	}
	while (abs(derivative_f - test_tolerance) >= 0.001); /*If the change between the last iteration and the current iteration is < 0.001 then
														the program exits the loop */

	//Display results
	cout << "Given the function " << c1 << "x^2 + " << c2 << "x + " << c3;
	cout << ",\nwhere the derivative was calculated at the point (" << x << "," << f_x << "),\n";

	cout << fixed << showpoint; //shows output of derivative_f in fixed decimal format
	cout << setprecision(3); //sets precision of output to three decimal points

	cout << "The derivative of the function is " << derivative_f << ".\n";
	cout << "The program repeated " << count << " times to reach this calculation.\n\n";

	//Return
	cout << "Enter any character and press enter to continue... "; cin >> wait;
	return 0;
}