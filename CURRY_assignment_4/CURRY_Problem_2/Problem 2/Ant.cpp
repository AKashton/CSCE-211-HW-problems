#include "Ant.h"

Ant::Ant(int x, int y) : Organism(currWorld, x, y)
{
	breedTracker = 3;
}

void Ant::breed()
{
	// checks if ant is ready to breed
	if (breedTracker > 3)
		return;
	//checks for valid moves around ant
	vector<int> getMoves = checkMoves(x, y);
	if (getMoves.size() == 0)
		return; // no valid moves, no breeding.
	//assigns a random move direction from the valid move options
	int randomMove = getMoves[currWorld->randomLocation(0, getMoves.size() - 1)];
	int newX = x;
	int newY = y;
	//assigns new coordinate area to ant
	getMove(newX, newY, randomMove);
	currWorld->world[x][y] = new Ant(currWorld, newX, newY);
	breedTracker = 3; //breed tracker reset for ant. 
}

int Ant::getType()
{
	return 2;
}
