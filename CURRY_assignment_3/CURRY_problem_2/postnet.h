/////////////////////////////////
// This class either takes a zipcode integer and converts it to a barcode string or
// takes a barcode string and converts it to a zipcode integer
////////////////////////////////
#pragma once
#include <iostream>
#include <string>

using namespace std;

class postnet
{
private:
	int code;

	//returns zipcode integer from input of a string barcode.
	int convertBartoInt(string barcode);

	//returns the barcode by converting the zipcode integer into a barcode string.
	string convertIntToBarcode(int code);

public:
	//takes a zip code and stores it as a integer (like 99503). Constructor 1.
	postnet(int zipcode);

	//takes a barcode and converts it into a zipcode, storing it as a integer. Constructor 2.
	postnet(string barcode);

	//returns the code in int form, which is the zipcode.
	int getZipcode();

	//returns barcode in string form
	string getBarcode();
};

