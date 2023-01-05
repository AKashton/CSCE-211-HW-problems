/******************************************
* Ashton Curry
* Assignment 1 problem 2
* Due: 9/20/2022
* This Program demonstrates the use of functions as well as how to design games.
* Chuck-a-luck game
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*****************************************************************
* Name: rollDice
* Description: This function simulates 3 dice rolls (1-6) and compares
* the rolled number with a user number (userNum, also 1-6) and determines
* if the roll and user number are the same.
* Inputs: user number between 1 and 6
* Returned value: the number of matching dice rolls the player got. 
*****************************************************************/
int rollDice(int userNum);

/*****************************************************************
* Name: betResult
* Description: This function calculates the Chuck-a-luck winnings/losings of the player.
* if the player has 1 dice equal, they get their money back, if two dice are equal, they double
* thier money, if 3 dice are the same as their number, they get 3 times their money.
* They lose their bet if they get 0 dice that are the same as their number. 
* Inputs: equivalent dice, players money, and their wager. 
* Returned value: passes parameter for playerMoney, but doesn't return a value explicitly. 
*****************************************************************/
void betResult(int diceEqual, int &playerMoney, int wager);

int rollDice(int userNum)
{
	int diceNums[3]; //represents 3 dice.
	int diceEqual = 0; // counts the dice that are equal to user number
	for (int i = 0; i < 3; i++) //rolls 3 dice
	{
		diceNums[i] = (rand() % 6) + 1;
		if (diceNums[i] == userNum)
			diceEqual++;
		cout << "dice roll " << i + 1 << " result: " << diceNums[i] << endl;
	}
	
	return diceEqual;
}
void betResult(int diceEqual, int &playerMoney, int wager)
{
	if (diceEqual == 0)
	{
		playerMoney = playerMoney;
		cout << "No dice equalled your number, better luck next time." << endl;
	}

	else if (diceEqual == 1)
	{
		playerMoney += wager;
		cout << "1 dice equalled your number, you made back your wager." << endl;
	}
	else if (diceEqual == 2)
	{
		playerMoney += (wager * 2);
		cout << "2 dice equalled your number. Congrats, you doubled your money!" << endl;
	}
	else if (diceEqual == 3)
	{
		playerMoney += (wager * 3);
		cout << "3 dice equalled your number. Congrats, you tripled your money! are you cheating?" << endl;
	}
}
	
int main()
{
	int playerMoney = 100; // starting money for player
	int wager; // players wager
	int userNum; // players chosen number
	char roll; // player character to roll dice.
	int diceEqual; //counts how many dice numbers are equal to player number.
	char play; // checks if a player wants to play again. 
	srand(time(NULL));
	while (playerMoney != 0)
	{
		do //gets a valid wager between the players money and 0. 
		{
			cout << "player money remaining: $" << playerMoney << endl;
			cout << "Please enter a valid Wager: " << endl;
			cin >> wager;
		} while (wager <= 0 || wager > playerMoney);
		
		do
		{
			cout << "Choose a number between 1 and 6 to bet on:" << endl;
			cin >> userNum;
		} while (userNum < 1 || userNum > 6);
		
		do
		{
			cout << "press d to roll the dice." << endl;
			cin >> roll;
			if (roll == 'd' || roll == 'D')
				diceEqual = rollDice(userNum);
		} while (roll != 'D' && roll != 'd');
	
		playerMoney -= wager; //subtracts wager from playerMoney
		betResult(diceEqual, playerMoney, wager); //calculates new player total
		cout << "New Player money: $" << playerMoney << endl;
		
		if (playerMoney == 0)
		{
			cout << "Sorry, you have run out of money. Get out of my casino!" << endl;
			break;
		}
			
		else
		{	
			do 
			{
				cout << "Play again? y or n" << endl;
				cin >> play;
			} while (play != 'y' && play != 'n');
		}
		if (play == 'n')
		{
			cout << "goodbye." << endl;
                        break;
		}
	}
	return 0;
}

