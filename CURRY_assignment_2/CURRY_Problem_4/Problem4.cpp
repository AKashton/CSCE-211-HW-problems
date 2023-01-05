/////////////////////////////////////////////////////////////////// 
// CSCE A211
// Ashton Curry
// Due Date: 10/14/22
// Problem 4: Decrypt the enemy message
// Purpose: to learn how to deal with typecasting with pointers.
///////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

/*****************************************************************
* Name: decryptMessage
* Description: takes a message then attemtps to decrypt it using a key
* Inputs: the key number 
* Returned value: Nothing is returned.
*****************************************************************/
void decryptMessage(int key);

void decryptMessage(int key)
{
	char message[17] = ",vtaNm a_\"dabp!!";
	
	for (int i = 0; i < 16; i += 4) // takes message and changes 4 characters at a time
	{
		int* ptr_int = (int*)(&message[i]); //changes 4 chars to 1 int
		*ptr_int -= key; //subtracks key to decrypt
		char* ptr_char = (char*)ptr_int; // changes int back into 4 chars
	}
	cout << "Key: " << key << " Message: " << message << endl;
}

int main()
{
	for (int i = 1; i <= 500; i++)
	{
		decryptMessage(i);
	}
	return 0;
}