/******************************************
* Ashton Curry
* Assignment 1 problem 1
* Due: 9/20/2022
* This Program demonstrates benfords law and uses I/O redirection to read a file into input
* for this program.
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int enroll_list[3295]; //holds the I/O redirect numbers.
	int numCounter[9] {0}; //holds 9 slots for the values of 1-9, acts as a counter to iterate through
	for (int i = 0; i < 3295; i++)
	{
		cin >> enroll_list[i]; //reads from the I/O redirect then completes counting for 1st digit
		if (enroll_list[i] >= 10) //accounts for entrollments above 10
		{
			if (enroll_list[i] >= 100) //accounts for enrollments above 100
				enroll_list[i] /= 100; //divides by 100 do get first digit of a 3 digit number.
			else
				enroll_list[i] /= 10; //divides by 10 to get first digit of a 2 digit number.
			for (int j = 0; j < 9; j++)
			{
				if (enroll_list[i] == (j + 1)) //iterates through the number counter to count first digit.
					numCounter[j]++;
			}
		}
		else if (enroll_list[i] < 10)
		{
			for (int j = 0; j < 9; j++)
			{
				if (enroll_list[i] == (j + 1))
					numCounter[j]++;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		cout << "Number of " << (i + 1) << "s: " << numCounter[i] << endl;
	}
}
