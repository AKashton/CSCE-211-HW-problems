/////////////////////////////////////////////////////////////////// 
// CSCE A211
// Ashton Curry
// Due Date: 11/8/22
// Assignment #3 Problem 1: Operator Overloading
// Purpose: understand the use of classes and multifile systems. 
///////////////////////////////////////////////////////////////////

#include <iostream>
#include "Pair.h"

using namespace std;

//Return a new pair that adds a integer on left side of operator and a object on the right side of operator.
Pair operator+(int otherNum, Pair& p)
{
	Pair newPair;
	newPair.num1 = otherNum + p.num1;
	newPair.num2 = otherNum + p.num2;
	return newPair;
}

// Return a new pair by adding two other pair objects.
Pair operator+(const Pair& other1, const Pair& other2)
{
	Pair newPair;
	newPair.num1 = other1.num1 + other2.num1;
	newPair.num2 = other1.num2 + other2.num2;
	return newPair;
}

// Return a new pair that adds a Pair object on the left and an int on the right
Pair operator+(Pair& p, int otherNum)
{
	Pair newPair;
	newPair.num1 = p.num1 + otherNum;
	newPair.num2 = p.num2 + otherNum;
	return newPair;
}


int main()
{
	Pair p1(5, 10);
	Pair p2(1, 2);

	// Outputs 5 and 10
	cout << p1.get1() << " " << p1.get2() << endl;
	// Outputs 1 and 2
	cout << p2.get1() << " " << p2.get2() << endl;

	Pair p3 = p2 + p1;
	// Outputs 6 and 12
	cout << p3.get1() << " " << p3.get2() << endl;

	//p3 = 2 + p3 did not work because the overloaded operator+ method only takes in arguments where the left side of the operator is a object and the right side is
	//a integer or where the left side and right side are both objects.
	//in the case of 2 + p3, the left side is an integer, so there was no method to take this into account. 
	p3 = p3 + 2;
	// Outputs 8 and 14
	cout << p3.get1() << " " << p3.get2() << endl;

	p3 = 2 + p3;
	//outputs 10 and 16 (proof of concept for adding a friend operator for an integer + a object.)
	cout << p3.get1() << " " << p3.get2() << endl;

}
