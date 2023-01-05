#include "Organism.h"
vector<int> Organism::checkMoves(int x, int y) const
{
    //checks and stores all valid moves into vector and returns the vector
    vector<int> validMoves;
    int tempX, tempY;
    for (int move = 1; move <= 4; move++) // Left is 1, right is 2, down is 3, and up is 4.
    {
        tempX = x;
        tempY = y;
        getMove(tempX, tempY, move);
        if (!validcoordinate(tempX, tempY))
            continue;
        //if the adjacent move (Left, right, down, up) is a nullptr, then organism could move there.
        if (currWorld->world[tempX][tempY] == nullptr)
            validMoves.push_back(move);
    }
    return validMoves;
}

bool Organism::validcoordinate(int x, int y) const
{
    //returns false if coordinate is outside the 20x20 world.
    if (x < 0 || x >= 20 || y < 0 || y >= 20)
        return false;
    return true;
}

//defines the movement of coodinates
void Organism::getMove(int& x, int& y, int move) const
{
    if (move == 1) x--; // left
    if (move == 2) x++; //right
    if (move == 3) y--; // down
    if (move == 4) y++; // up
}
//creates new world for sim if values aren't input.
Organism::Organism()
{
    currWorld = nullptr;
    x = 0;
    y = 0;
    breedTracker = 0;
    tStepCnt = 0;
}

//adds new organism to world at specific coordinates with current time step.
Organism::Organism(int x, int y)
{
    this->currWorld = currWorld;
    this->x = x;
    this->y = y;
    breedTracker = 0;
    tStepCnt = currWorld->tStepCnt; //accesses world cnt for time steps. 

}

//moving function for both ants and doodles 
void Organism::move()
{
    if (tStepCnt == currWorld->tStepCnt)
        return;
    tStepCnt++;
    breedTracker--;
    int randomMove = currWorld->randomLocation(1, 4); //uses random generator to choose movements (1-4 represented by left, right, down and up respectively)
    int newX = x;
    int newY = y;
    getMove(newX, newY, randomMove);
    if (validcoordinate(newX, newY))
    {
        if (currWorld->world[newX][newY] != nullptr)
            return;
        currWorld->world[x][y] = nullptr;
        currWorld->world[newX][newY] = this;
        x = newX;
        y = newY;
    }
}

bool Organism::starve()
{
    return false;
}
