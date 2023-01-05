#include "Prisoner.h"
//defaults to prisoner 0 and nullptr, but hopefully will never need.
Prisoner::Prisoner()
{
	num_prisoner = 0;
	next = nullptr;
}

Prisoner::Prisoner(int numPrisoner)
{
	this->num_prisoner = numPrisoner;
	next = nullptr;
}

void Prisoner::setPrisonerNum(int numPrisoner)
{
	num_prisoner = numPrisoner; 
}

int Prisoner::getPNum()
{
	return num_prisoner;
}

void Prisoner::setNext(Prisoner* next)
{
	this->next = next;
}

Prisoner* Prisoner::getNext()
{
	return next;
}
