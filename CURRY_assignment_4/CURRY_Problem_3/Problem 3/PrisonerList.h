#pragma once
#include "Prisoner.h"
class PrisonerList
{
private:
	Prisoner* head; //points to prisoner 1
public:
	PrisonerList();
	~PrisonerList(); //erases list from heap after out of scope.
	void add(int p); //adding prisoner with number p to linked list. uses the last node to loop.
	int execute(int w); //removes prisoners with 

}; 

