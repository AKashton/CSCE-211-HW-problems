/////////////////////////////////////////////////////////////////// 
// CSCE A211
// Ashton Curry
// Due Date: 11/8/22
// Assignment #3 Problem 5: Maze Class
// Purpose: use classes instead of functions to represent the maze solution from problem 2 homework 2.
///////////////////////////////////////////////////////////////////

// maze-solver.cpp
//
// This program fills in a maze with random positions and then runs the solver to solve it.
// The moves are saved in two arrays, which store the X/Y coordinates we are moving to.
// They are output in main in forward order.
//

#include "Maze.h"


int main()
{
	// Seed random number generator with clock time
	srand(time(NULL));
	Maze newMaze;
	
	//creates maze and searches for a solution. 
	bool found = newMaze.startSearch();
	if (!found) //if no solution for the maze generated is found, this will print.
		cout << "No solution found.";
	else
	{
		cout << "Solution found!  Here is the path from the start." << endl;

		//prints the solution of the maze if found.
		newMaze.printSolution();
	}
}