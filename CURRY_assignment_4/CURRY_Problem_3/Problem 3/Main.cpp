/******************************************
* Ashton Curry
* Assignment 4 problem 3: Game of Death
* Due: 12/8/22
* Use a cicular linked list to correctly create a pedictor of who will die in the game, and use 
* this to your advantage to place yourself in the last man standing spot
******************************************/
#include <iostream>
#include "Prisoner.h"
#include "PrisonerList.h"
using namespace std;
/*some things to check: 1. inputs from user need to pass in the number of prisoners, and the number of words for selection 
of prisoners. the output from the program should say "with [# of prisoners] prisoners and [# words], I'd like to be number [surviver #]"

Classes: 1 class called prisoner that is a node, containing prisoner number and a pointer to the next 
prisoner in the list.
1 more class for the linked list of prisoners. 

*/

int main()
{
	int p; //# prisoners
	int w; //# words
	cout << "welcome to the arena, how many prisoners?" << endl;
	cin >> p;
	cout << "how many words would you like?" << endl;
	cin >> w;
	cout << "So we begin." << endl;
	PrisonerList prisonlist;
	for (int i = 1; i <= p; i++) //adds all prisoners to linked list in order (1-#prisoners)
	{
		prisonlist.add(i);
	}
	int winner = prisonlist.execute(w); //iterates through linked list and deletes each node cooresponding to rules.

	cout << "With " << p << " prisoners and " << w << " words, I'd like to be number " << winner << "." << endl;
	
}