#pragma once
#include "Organism.h"
using namespace std;
class Ant : public Organism
{
public:
	Ant() : Organism() {};
	Ant(int x, int y);
	void breed();
	int getType(); //returns 2 for ant. 
};

