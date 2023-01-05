#pragma once
class Prisoner
{
private:
	int num_prisoner; //stores prisoner number for unique "ID"
	Prisoner* next; //store memory address for next prisoner in line
public:
	Prisoner(); //defualt constructor
	Prisoner(int numPrisoner); // constructor with specified prisoner number 
	void setPrisonerNum(int numPrisoner); //setter for each prisoner number 
	int getPNum(); //getter for prisoner num
	void setNext(Prisoner* next); //setter for the memory address of next prisoner node
	Prisoner* getNext(); //getter for memory address of next prisoner in node
};

