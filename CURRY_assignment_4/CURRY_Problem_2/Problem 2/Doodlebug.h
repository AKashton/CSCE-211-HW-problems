#pragma once
#include "Organism.h"
using namespace std;
class Doodlebug : public Organism
{
private:
	//tracks starving time left
	int starveTime;

	//move towards ants as long as move is valid
	vector<int> moveToAnt(int x, int y) const;
public:
	Doodlebug(int x, int y);
	void breed();
	void move();
	int getType();
	bool starve();

};

