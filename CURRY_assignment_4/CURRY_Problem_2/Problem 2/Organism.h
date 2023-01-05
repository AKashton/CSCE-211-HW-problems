#pragma once
#include <vector>
#include "World.h"
using namespace std;
//parent class to both doodlebugs and ants. sets up 

class World;
class Organism
{
protected:
	World* currWorld; //start of a new world for organisms to interact with
	int x; //x coordinate
	int y; //y coordinate
	int tStepCnt; // tracks time steps
	int breedTracker; // tracks time until next breed
	//checks all valid moves for organism on map. stores all options in vector
	vector<int> checkMoves(int x, int y) const;
	bool validcoordinate(int x, int y) const; //checks to see if move is valid
	void getMove(int& x, int& y, int move) const; // updates x and y for movement. (orgranism position)

public:
	Organism();
	Organism(int x, int y);
	//move funtion for both ants and doodle (they have the same moving conditons)
	virtual void move();
	//breeding condtions, different for both ants and doodles, so pure virtual.
	virtual void breed() = 0;
	//starve only applies to doodles
	virtual bool starve();
	virtual int getType() = 0; //defines organism type, 1 = doodlebug, 2 = ant.
};

