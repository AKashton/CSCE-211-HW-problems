/******************************************
* Ashton Curry
* Assignment 4 problem 2: Doodlebug Simulation
* Due: 12/8/22
* This Program simulates a predator-prey game where a doodle bug is a predator ('X') and a ant is prey ('o').
******************************************/


#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "World.h"
using namespace std;


int main()
{
	char userinput;
	World w;

	cout << "Are you ready to sim doodlebugs vs ants?" << endl;
	cout << "Press any key to begin and timestep the simulation, and q to stop the program" << endl;
	cin.get(userinput);

	w.startSim();
	cout << "simulation has begun." << endl;
	w.printWorld();
	cout << endl;

	while (userinput != 'q')
	{
		w.timeStep();
		w.printWorld();
		cout << endl;
		cout << "hit any key but q to go another time step, and q to quit" << endl;
		cin.get(userinput);
	}

	cout << "ending simulation" << endl;
}