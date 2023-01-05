#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
//global assignment of valid movments
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int UP = 4;

//global assignment for doodle/ant selction
const int DOODLEBUG = 1;
const int ANT = 2;

int SIZE = 20; // dimensions for the world
const int DOODLE_START = 5; //the doodlebugs that are present at the start of the sim
const int ANT_START = 100; // ants that are present at start of sim

const int DOODLE_BREED = 8; //time steps it takes for doodle bugs to breed
const int ANT_BREED = 3; //time steps it takes for ants to breed

const int DOODLE_STARVE = 3; //time steps it takes for a doodlebug to starve without eating ants

typedef Organism* OrganismPtr; //pointer to orgranism class
typedef World* WorldPtr; //pointer to world class