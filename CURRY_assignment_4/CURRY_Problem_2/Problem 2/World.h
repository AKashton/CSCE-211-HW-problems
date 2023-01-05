#pragma once
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iostream>
#include "Ant.h"
#include "Doodlebug.h"
using namespace std;
class Organism;

class World
{
	
private:
	int tStepCnt; //tracks the number of time steps in the sim
	int randomLocation(int start, int end) const; //random number generator for selecting spots in the world
	Organism* world[20][20]; //defines dimensions for the doodlebugs and ants
public:
	World();
	void startSim(); //starts the simulation
	void timeStep(); // completes timestep action and starts move, breed, and starve conditional checks.
	void printWorld() const; //prints world 

	friend class Organism;
	friend class Doodlebug;
	friend class Ant;
};


