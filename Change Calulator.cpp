#include <iostream>
#include <iomanip>

using namespace std;

double nextCoin(double changeDue);
int numberCoins(double total, double value);

int main()
{
	//declare variables
	char choice = 'y';
	double purchasePrice;
	double amountPaid;
	double changeDue;
	double coinNumber;
	double coinValue;
	char wait;
	//introduce program to user
	cout << "Welcome to Change Calculator!\n You will be asked to provide \n";
	//loop getting values from the user
	while ((choice == 'y') || (choice == 'Y'))
	{
		//get total purchase price
		cout << "Please enter the purchase price in dollars and cents (xx.yy): "; cin >> purchasePrice; cout << endl;

		//get amount paid
		cout << "Please enter the amount paid in dollars and cents: "; cin >> amountPaid; cout << endl;

		//calculate amount of change due
		changeDue = amountPaid - purchasePrice;

		//determine coins needed
	while (changeDue > 0.01)
		{
			//what is the next coin value
			coinValue = nextCoin(changeDue);

			//how many of these coins?
			coinNumber = numberCoins(changeDue, coinValue);
			
			//tell user how many + type
			cout << "Please give " << coinNumber << " of " << coinValue << endl;

			//adjust total
			changeDue = changeDue - (coinNumber * coinValue);

		}
		
		//ask if user wants to continue
		cout << "Do you want to keep going? (Y/N)"; cin >> choice;
	}
	//Return
	cout << "Enter any character and press enter to continue... "; cin >> wait;
	return 0;
}
double nextCoin(double changeDue)
{
	if (changeDue >= 1.00)
		return 1.00;
	else if (changeDue >= 0.25)
		return 0.25;
	else if (changeDue >= 0.10)
		return 0.10;
	else if (changeDue >= 0.05)
		return 0.05;
	else if (changeDue >= 0.01)
		return 0.01;
	else
		return 0;
}

int numberCoins(double total, double value)
{
	return total / value;
}