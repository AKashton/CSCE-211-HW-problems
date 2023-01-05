/******************************************
* Ashton Curry
* Assignment 4 problem 4: Templates and Exceptions
* Due: 12/8/22
* This program dmonstrates the usage of templates and exceptions.
******************************************/
#include "ArrayOutOfRange.cpp"
#include "CheckedArray.cpp"
using namespace std;


int main()
{
	CheckedArray <int> MyArray(6);

	cout << "\n Length: " << MyArray.length() << endl;
	cout << "\n Original array: ";

	MyArray.show();

	MyArray[2] = 60;

	cout << "\n After assign 60 at 2 index position: ";
	MyArray.show();

	cout << "\n Generates exception by assigning 90 at 8 index position." << endl;
	MyArray[8] = 90;

}
