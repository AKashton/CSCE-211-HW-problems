#include "Doodlebug.h"

//checks for valid moves towards ajacent ants, then stores all possible moves
vector<int> Doodlebug::moveToAnt(int x, int y) const
{
	vector<int> moveToAnt;
	int tempX, tempY;
	for (int move = 1; move <= 4; move++)
	{
		tempX = x;
		tempY = y;
		getMove(tempX, tempY, move);
		if (!validcoordinate(tempX, tempY))
			continue;
		if (currWorld->world[x][y] == nullptr)
			continue;
		if (currWorld->world[x][y]->getType() == 2) //2 = ant
			moveToAnt.push_back(move);
	}
	return moveToAnt;
}

Doodlebug::Doodlebug(int x, int y)
{
	//sets condtional starve and breed to doodlebug 
	starveTime = 3;
	breedTracker = 8;
}
//checks for breeding, then duplicates doodlebug to random adjacent move area
void Doodlebug::breed()
{
	//no breed if tracker isn't zero.
	if (breedTracker > 0)
		return;
	//checks all valid spaces for new doodlebug
	vector<int> getMoves = checkMoves(x, y);
	//if there is no empty cells around bug, no breeding occurs
	if (getMoves.size() == 0)
		return;
	//checks to see all locations possible, then assings location for new breeded doodle.
	int randomMove = getMoves[currWorld->randomLocation(0, getMoves.size() - 1)];
	int newX = x;
	int newY = y;
	getMove(newX, newY, randomMove);
	//creates new doodlebug at valid coordinates in world.
	currWorld->world[newX][newY] = new Doodlebug(newX, newY);
	breedTracker = 8;
}

//moves doodlebug, with the cavet of moving towards ants
void Doodlebug::move()
{
	if (tStepCnt == currWorld->tStepCnt) 
		return;
	vector<int> moveAnt = moveToAnt(x, y);
	if (moveAnt.size() == 0) 
	{
		Organism::move();
		starveTime--;
		return;
	}
	tStepCnt++;
	starveTime = 3;
	int randomMove = moveAnt[currWorld->randomLocation(0, moveAnt.size() - 1)];
	int antX = x;
	int antY = y;
	getMove(antX, antY, randomMove);
	delete currWorld->world[antX][antY];
	currWorld->world[antX][antY] = this;
	currWorld->world[x][y] = nullptr;
	x = antX;
	y = antY;
}

//assigns the doolebug class to our doodlebug type.
int Doodlebug::getType()
{
	return 1;
}

//returns true when doodlebug starve timer reaches zero.
bool Doodlebug::starve()
{
	return starveTime == 0;
}
