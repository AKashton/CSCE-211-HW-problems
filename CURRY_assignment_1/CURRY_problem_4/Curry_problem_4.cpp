/******************************************
* Ashton Curry
* Assignment 1 problem 4
* Due: 9/20/2022
* This Program demonstrates pass by reference and is used to determine the smallest
* amount of coins needed for a given amount of change.
******************************************/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
/*****************************************************************
* Name: coinCounter
* Description: determines the minimal number of coins needed from a given amount of change.
* Inputs: change, pass by reference values for quarters, dimes, nickles, and pennies.
* Returned value: No return value.
*****************************************************************/
void coinCounter(int change, int& quarters, int& dimes, int& nickels, int& pennies);

void coinCounter(int change, int& quarters, int& dimes, int& nickels, int& pennies)
{
		quarters = change / 25; // determines quarter amount
		dimes = (change % 25) / 10; // determines dimes (subtracts quarters through mod)
		nickels = ((change % 25) % 10) / 5; // determines nickels (subtracts quarters and dimes w/ mod)
		pennies = (((change % 25) % 10 ) % 5); // determines pennies (subtracts Qs, Ds, and Ns w/ mod)
}
int main()
{
	int change[2] = { 68, 23 }; //test values
	int userchange = 0; // input value holder
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;
	int coinCount = 0; //number of coints total needed.

	for (int i = 0; i < 2; i++)
	{
		cout << "Test change " << i + 1 <<" value: " << change[i] << endl;
		coinCounter(change[i], quarters, dimes, nickels, pennies);
		coinCount = quarters + dimes + nickels + pennies;
		cout << "Quarters: " << quarters << "\nDimes: " << dimes << "\nNickels: " << nickels
			<< "\nPennies: " << pennies << "\nTotal coins: " << coinCount << "\n" << endl;
	}

	do //loops until user inputs a valid # between 1-9, and gives them their change.
	{
		cout << "Please input change between 1-99" << endl;
		cin >> coinCount; 
		if (coinCount >= 1 && coinCount <= 99)
		{
			coinCounter(coinCount, quarters, dimes, nickels, pennies);
			coinCount = quarters + dimes + nickels + pennies;
			cout << "Your change:" << "\nQuarters: " << quarters << "\nDimes: " << dimes << "\nNickels : " << nickels
				<< "\nPennies: " << pennies << "\nTotal coins: " << coinCount << "\n" << endl;
		}
	} while (coinCount <= 0 || coinCount >= 100);

	return 0;
}
