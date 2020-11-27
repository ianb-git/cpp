/*Name: Derivative Calculator *FUNCTION EDITION*
Author: Ian Breckenridge
Date: 02 November 2017
Description: Derivative Calculator *FUNCTIONS EDITION* uses the limit definition of a derivative in a do...while loop to calculate the
instantaneous slope of a quadratic as "h" (or delta x) approaches 0, and uses functions to describe different aspects of the program*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double quad_eq(double c1, double x, double c2, double c3);
double deriv_eq(double f_x, double f_x_plus_h, double h);
void greeting();
void input(double& c1, double& c2, double& c3, double& x);
void output(double c1, double c2, double c3, double x, double f_x, double deriv_f, int count);

int main()
{
	//Definitions and Declarations
	double c1, c2, c3; /*coefficient for "x^2" in quadratic equation; coefficient for "x"
					   in quadratic equation, constant (values determined by user)*/

	double x, f_x, f_x_plus_h; /*"x" value where quadratic equation is evaluated and derivative is taken 
							   (determined by user); variable where value of quadratic equation evaluated 
							   at "x" is stored; variable where value of quadratic equation evaluated at "x+h" is stored*/

	double test_tolerance = 0.001, deriv_f = 0.001; /*variable that is set to the value of derivative_f in the last iteration of the test;
													value of difference between f_x_plus_h and f_x divided by h (calculates slope as h -> 0),
													derivative set to 0.001 so test_tolerance is not changed on first pass through do...while loop*/

	double h = 0.1; /*this is the change in x(delta x), which is halved after each iteration of the do...while
					loop to increase accuracy*/

	int count = 0; //counts repetitions of do...while loop
	char wait; //Prevents program from automatically closing once values needed to be calculated are input

	//Introduce program to user
	greeting(); //Greeting function that introduces program to user

	//Get input data from user
	input(c1, c2, c3, x); //Input function that takes input data from user

	//Sets value of quadratic equation "f_x" to be in used in do...while loop
	f_x = quad_eq(c1, x, c2, c3); //quadratic function that sets value of f_x

	//Do...while loop which calculates derivative of function based on repeated iterations
	do
	{
		test_tolerance = deriv_f; //sets test_tolerance equal to the previous derivative

		f_x_plus_h = c1 * (x + h) * (x + h) + c2 * (x + h) + c3; //Sets new value for f(x+h) based on change in h
		deriv_f = deriv_eq(f_x, f_x_plus_h, h); //derivative function that calulates value of deriv_f for this iteration of test 

		count++; //increments count variable by 1 to indicate the do...while loop was iterated

		h = h / 2; //halves h for next iteration to increase accuracy (essentially "taking the limit" by decreasing interval to approach 0)
	} while (abs(deriv_f - test_tolerance) >= 0.001); /*If the change between the last iteration and the current iteration is < 0.001 then
													  the program exits the loop */
	//Display results
	output(c1, c2, c3, x, f_x, deriv_f, count); //output function that displays results of program to the user

	//Return
	cout << "Enter any character and press enter to continue... "; cin >> wait;

	return 0;
}

/*Function Name: Quadratic Equation
Function Author: Ian Breckenridge
Date: 02 November 2017*/
double quad_eq(double c1, double x, double c2, double c3)
{
	return c1 * x * x + c2 * x + c3;
}

/*Function Name: Derivative Equation
Function Author: Ian Breckenridge
Date: 02 November 2017*/
double deriv_eq(double f_x, double f_x_plus_h, double h)
{
	return (f_x_plus_h - f_x) / h;
}

/*Function Name: Greeting Function
Function Author: Ian Breckenridge
Date: 02 November 2017*/
void greeting()
{
	cout << "Welcome to derivative calculator!\n\nYou will be asked";
	cout << " to provide the coefficients of the quadratic equation\n(of the form";
	cout << " c1 * x^2 + c2 * x + c3) and the value";
	cout << " for x at which the \nderivative is to be found.\n\n";
}

/*Function Name: Input Function
Function Author: Ian Breckenridge
Date: 02 November 2017*/
void input(double& c1, double& c2, double& c3, double& x)
{
	cout << "Please input a value for c1 (\"x^2\" coefficient): "; cin >> c1; cout << "\n";
	cout << "Please input a value for c2 (\"x\" coefficient): "; cin >> c2; cout << "\n";
	cout << "Please input a value for c3 (constant): "; cin >> c3; cout << "\n";
	cout << "Please input a value for x: ";  cin >> x; cout << "\n";
}

/*Function Name: Output Function
Function Author: Ian Breckenridge
Date: 02 November 2017*/
void output(double c1, double c2, double c3, double x, double f_x, double deriv_f, int count)
{
	cout << "Given the function " << c1 << "x^2 + " << c2 << "x + " << c3;
	cout << ",\nwhere the derivative was calculated at the point (" << x << "," << f_x << "),\n";

	cout << fixed << showpoint; //shows output of deriv_f in fixed decimal format
	cout << setprecision(3); //sets precision of output to three decimal points

	cout << "The derivative of the function is " << deriv_f << ".\n";
	cout << "The program repeated " << count << " times to reach this calculation.\n\n";
}