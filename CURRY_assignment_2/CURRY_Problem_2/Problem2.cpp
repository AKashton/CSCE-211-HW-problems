/////////////////////////////////////////////////////////////////// 
// CSCE A211
// Ashton Curry
// Due Date: 10/14/22
// Problem 2: Maze generation (random)
// Purpose: generate a random maze and have it solved, also print the maze in forward direction from start to finish. 
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

// Function prototypes

//prints the maze
void printMaze(char maze[][WIDTH], int curx, int cury);
//assigns areas with true or false for if the user has moved there or not. 
bool validMove(char maze[][WIDTH], bool visited[][WIDTH],int newX, int newY);
//searches maze for solution
bool search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y, int &counter, int a[], int b[]);
//generates 25% of the maze with random walls.
void randomWall(char maze[][WIDTH]);
//generates a random start area of the maze.
void mazeStart(char maze[][WIDTH], int &x, int &y);
//generates a random end area of the maze.
void mazeExit(char maze[][WIDTH], int x, int y);

// Return true or false if moving to the specified coordinate is valid
// Return false if we have been to this cell already
bool validMove(char maze[][WIDTH], bool visited[][WIDTH],
	int newX, int newY)
{
	// Check for going off the maze edges
	if (newX < 0 || newX >= WIDTH)
		return false;
	if (newY < 0 || newY >= HEIGHT)
		return false;
	// Check if target is a wall
	if (maze[newY][newX] == 'X')
		return false;
	// Check if visited
	if (visited[newY][newX])
		return false;
	return true;
}


// Display the maze in ASCII
void printMaze(char maze[][WIDTH], int curx, int cury)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((x == curx) && (y == cury))
				cout << "@";
			else
				cout << maze[y][x];
		}
		cout << endl;
	}
}

// Recursively search from x,y until we find the exit
bool search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y, int &counter, int a[], int b[])
{
	
	if (maze[y][x] == 'E')
	{
		return true;
	}
	
	bool foundExit = false;
	visited[y][x] = true;
	if (validMove(maze, visited, x, y - 1))
		foundExit = search(maze, visited, x, y - 1, counter, a, b);
	if (!foundExit && (validMove(maze, visited, x, y + 1)))
		foundExit = search(maze, visited, x, y + 1, counter, a, b);
	if (!foundExit && (validMove(maze, visited, x - 1, y)))
		foundExit = search(maze, visited, x - 1, y, counter, a, b);
	if (!foundExit && (validMove(maze, visited, x + 1, y)))
		foundExit = search(maze, visited, x + 1, y, counter, a, b);

	if (foundExit)
	{
		a[counter] = x; //saves each coordinate for x 
		b[counter] = y; // saves each coordinate for y
		counter++; // incriments up each call. 
		return true;
	}
	return false;
}

//randomly assigns 25% of the maze with walls.
void randomWall(char maze[][WIDTH])
{
	// counts the amount of walls placed (need 81 walls in 18x18 maze to fill 25%)
	int wallcounter = 0;
	do
	{
		int x = (rand() % 18) + 1;
		int y = (rand() % 18) + 1;

		if (maze[y][x] != 'X')
		{
			maze[y][x] = 'X';
			wallcounter++;
		}
	} while (wallcounter != 81);
}

//randomly places the start position of the maze.
void mazeStart(char maze[][WIDTH], int &x, int &y)
{
	do 
	{
		x = (rand() % 18) + 1;
		y = (rand() % 18) + 1;
	}while (maze[y][x] == 'X');
}

//randomly places the exit position of the maze.
void mazeExit(char maze[][WIDTH], int x, int y)
{
	int a = 0;
	int b = 0;
	do
	{
		a = (rand() % 18) + 1;
		b = (rand() % 18) + 1;

	//ensures that the Exit and start aren't in the same place
	} while (maze[b][a] == 'X' || (a == x && b == y) ); 

	maze[b][a] = 'E';
}
int main()
{
	char maze[HEIGHT][WIDTH] = {
		   {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		   {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
	};
	bool visited[HEIGHT][WIDTH];

	srand(time(NULL));
	int x = 1, y = 1; 
	int counter = 0; // counts the moves made for the maze, to print later in foward order.
	int a[400]; //stores x coordinates to print in forward order
	int b[400]; //stores y coordinates to print in forward order
	bool foundExit = false;
	//create 25% of maze having random walls
	randomWall(maze);

	//randomly assigns the starting position
	mazeStart(maze, x, y);

	//randomly assigns the Exit position
	mazeExit(maze, x, y);

	// Initialize visited locations to false
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGHT; y++)
			visited[y][x] = false;
	visited[y][x] = true;

	//solves the maze, returns saved coordinates how many steps there were with counter. 
	search(maze, visited, x, y, counter, a, b);
	
	//goes backwards from the counter to 0 to iterate through the arrays created in the search function
	for (int i = counter - 1; i >= 0; i--) 

	{
		printMaze(maze, a[i], b[i]);
	}
	return 0;
}