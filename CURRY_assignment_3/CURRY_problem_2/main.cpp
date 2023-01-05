/////////////////////////////////////////////////////////////////// 
// CSCE A211
// Ashton Curry
// Due Date: 11/8/22
// Assignment #3 Problem 2: POSTNET
// Purpose: design a class that can read and output POSTNET barcodes into zip codes.
///////////////////////////////////////////////////////////////////
#include "postnet.h"


int main()
{
	//two objects, one zipcode integer and one barcode string.
	postnet zipcode(99504);
	postnet barcode("110100101000101011000010011");
	

	//converts barcode to zipcode and prints out starting binary representation and zipcode.
	cout << "barcode given: " << barcode.getBarcode() << endl;
	cout << "barcode to zipcode: " << barcode.getZipcode() << endl;

	//converts zipcode to binary and prints out the zipcode and barcode repesentation.
	cout << "zicode given: " << zipcode.getZipcode() << endl;
	cout << "zipcode to barcode: " << zipcode.getBarcode() << endl;
	
	return 0;
}