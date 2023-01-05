#include "PrisonerList.h"

PrisonerList::PrisonerList()
{
	head = nullptr; // no list active yet, head just points to null
}
//removes the link list of prisoners once out of scope (for this assignment, just when main ends.)
PrisonerList::~PrisonerList()
{
	Prisoner* temp = this->head;
	Prisoner* deletelist;
	do //if there are still other nodes, run this. 
	{
		deletelist = temp;
		temp = temp->getNext();
		delete deletelist;
	} while (temp != this->head);
	this->head = nullptr; //no nullptr tail, most of the time the only node left is the head and it points to itself, so gotta remove it this way
}

void PrisonerList::add(int p)
{
	Prisoner* temp = new Prisoner(p);
	Prisoner* last = head; // saves head to start iteration through list to find end of list.
	if (head == nullptr) //for first node, it will point to itself
	{
		head = temp;
		head->setNext(head);
	}
	else //iterates through list until we are at last node (should be pointing to head) and adds to the end
	{
		do
		{
			last = last->getNext();

		} while (last->getNext() != head);
		temp->setNext(last->getNext()); //sets new node to last, and points to head
		last->setNext(temp); //sets previous last to point to new last
	}
}

//executes prisoner by iterating through the # of words, then deleting the node it lands on.
int PrisonerList::execute(int w) //w is equal to # of words, head should change everytime new execution occurs. 
{

	//base case: 1 node remains, return prisoner number. 
	//needs to iterate through prisoner list w times, and whichever prisoner
	//it lands on, needs to setNext for previous node to the nodes get next that will be deleted.
	//then, set the head to equal the getNext pointer to start on the next iteration.
	
	while (head->getNext() != head)
	{
		Prisoner* temp = head; // start at "head" which should be set to the prisoner 
		Prisoner* prev = nullptr;
		for (int i = 1; i < w; i++) //rotates through list and sets temp to node to be deleted
		{
			prev = temp; //saves previous node
			temp = temp->getNext(); //keeps point to next node (set to "head at first);
		}
		if (w == 1) //takes into account if the word is one, then returns last prisoner (would always be the last prisoner to be survivor)
		{
			while (temp->getNext() != head)
			{
				temp = temp->getNext();
			}
			return temp->getPNum();
		}
		prev->setNext(temp->getNext()); //takes prisoner node before prisoner to be executed and points to next prisoner 
		head = temp->getNext(); //sets head to point to prisoner after executed prisoner. thus count restarts at next prisoner. 
		delete temp;
		
	}
	return head->getPNum();
}
