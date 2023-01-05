//cpp file for postnet class
#include "postnet.h"


//takes a barcode string, and converts it into a zipcode integer.
int postnet::convertBartoInt(string barcode)
{
	string tempstr = ""; //used to store each digit as its converted to a decimal number
	for (int i = 1; i < 26; i += 5)
	{
		string onedigit = ""; // used to hold each digit converted from the 5 bit codes. 
		//the equation uses ascii values to convert to decimal strings.
		onedigit += (7 * (barcode[i] - '0')) + (4 * (barcode[i + 1] - '0')) + (2 * barcode[i + 2] - '0')
			+ (barcode[i + 3] - '0');
		// getting the value of 11 is the same as the semi colon in ascii. 
		if (onedigit == ";") 
			onedigit = '0';
		
		tempstr += onedigit; //each digit added to our final zipcode string

	}
	int bartoint = stoi(tempstr); //converts zipcode string to an integer. 
	return bartoint;
}

//takes user zipcode and saves it as the integer zipcode. 
postnet::postnet(int zipcode)
{
	code = zipcode;
}

//takes user barcode and saves it to class barcode variable.
postnet::postnet(string barcode)
{
	code = convertBartoInt(barcode);
}

//returns zipcode
int postnet::getZipcode()
{
	return code;
}

//returns barcode
string postnet::getBarcode()
{
	return convertIntToBarcode(code);
}

//converts a zipcode integer into a barcode string
string postnet::convertIntToBarcode(int code)
{

	string inttobar = ""; //saves converted integers into binary string.
	while (code != 0)
	{
		int digit = code % 10; // gets furthest right digit.
		switch (digit) //use a switch statement to match each digit with cooresponding 5 bit code. (0 - 9)
		{
		case 0:
			inttobar = "11000" + inttobar;
			break;
		case 1:
			inttobar = "00011" + inttobar;
			break;
		case 2:
			inttobar = "00101" + inttobar;
			break;
		case 3:
			inttobar = "00110" + inttobar;
			break;
		case 4:
			inttobar = "01001" + inttobar;
			break;
		case 5:
			inttobar = "01010" + inttobar;
			break;
		case 6:
			inttobar = "01100" + inttobar;
			break;
		case 7:
			inttobar = "10001" + inttobar;
			break;
		case 8:
			inttobar = "10010" + inttobar;
			break;
		case 9:
			inttobar = "10100" + inttobar;
			break;
		}
		code /= 10; //drops off the furthest right digit to continue iterating through the zipcode
	}
	inttobar = "1" + inttobar + "1"; //barcode has 1s on both ends of string after formation of core 1s and 0s.
	
	return inttobar;
}
