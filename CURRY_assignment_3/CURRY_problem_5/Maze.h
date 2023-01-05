#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// ************ Width and Height changed to 20x20  ********************
const int WIDTH = 20;
const int HEIGHT = 20;

class Maze
{
public:
	
	Maze(); //default constructor, just used to print out "need coordinates" incase.
	
	//searches for an exit
	bool startSearch();

	//prints solutions
	void printSolution();

	
private:
	char maze[HEIGHT][WIDTH];
	bool visited[HEIGHT][WIDTH];
	int x;
	int y;
	int solutionX[(HEIGHT - 2) * (WIDTH - 2)], solutionY[(HEIGHT - 2) * (WIDTH - 2)];
	int numEntries = 0;

	//saves the coordinates for the solution to the maze.
	void addToArrays(int x[], int y[], int& numEntries, int xVal, int yVal);
	//used to print maze.
	void printMaze(int curx, int cury);
	//recursively search from x,y until we find the exit
	bool search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y, int solutionX[], int solutionY[], int& numEntries);
	//checks to see if the new movment is valid within the search recursion
	bool validMove(char maze[][WIDTH], bool visited[][WIDTH],
		int newX, int newY);
	//sets new location if move is valid
	bool move(char maze[][WIDTH], bool visited[][WIDTH],
		int& curX, int& curY, int newX, int newY);
};

