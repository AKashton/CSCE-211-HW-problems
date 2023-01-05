/******************************************
* Ashton Curry
* Assignment 3 problem 4
* Due: 11/8/22
* This Program demonstrates benfords law and uses fstreams to input data from a file
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream enrollments;
	int enroll_num; //holds a line of enrollment numbers.
	int numCounter[9]{ 0 }; //holds 9 slots for the values of 1-9, acts as a counter to iterate through

	enrollments.open("enrollments.txt"); // opens file
	if (!enrollments.is_open()) // checker to ensure file was open
	{
		cout << "Could not open file enrollments.txt." << endl;
		return 1;
	}

	while (enrollments >> enroll_num) //reads through each line of enrollments until the end of file.
	{
		
		if (enroll_num >= 10) //accounts for entrollments above 10
		{
			if (enroll_num >= 100) //accounts for enrollments above 100
				enroll_num /= 100; //divides by 100 do get first digit of a 3 digit number.
			else
				enroll_num /= 10; //divides by 10 to get first digit of a 2 digit number.
			for (int j = 0; j < 9; j++)
			{
				if (enroll_num == (j + 1)) //iterates through the number counter to count first digit.
					numCounter[j]++;
			}
		}
		else if (enroll_num < 10)
		{
			for (int j = 0; j < 9; j++)
			{
				if (enroll_num == (j + 1))
					numCounter[j]++;
			}
		}
	}
	enrollments.close();
	for (int i = 0; i < 9; i++)
	{
		cout << "Number of " << (i + 1) << "s: " << numCounter[i] << endl;
	}
	return 0;
}
