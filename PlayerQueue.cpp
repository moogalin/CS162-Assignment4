/******************************************************************************************
** Program Filename: Assignment 4
** Author: Megan Aldridge
** Date: February 28, 2016
** Description: This program allows a user to create two teams of Creatures that will
**		battle in pairs until death!
** Input: User will select the number of players in each team and then the user will select
**		from a menu to determine which Creatures will fight and name each creature.
** Output: The output displays each round of the fight including each creatures armor,
**		die roll, strength (before and after defending), and the result of the battle.
**		At the end of all paired battles, the output will display the players remaining
**		in the winning team and the losers (incapacitated players) as well as the 1st,
**		2nd, and 3rd place victors.
**		Menu functions also display choices to allow the user to determine if they want
**		to continue the battle, start a new one, or quit.
******************************************************************************************/

#include "PlayerQueue.hpp"

/******************************************************************************************
** Function: Constructor
** Description: This functions sets the head and tail pointers to NULL when a new Queue 
**		is instantiated.
** Parameters: N/A
** Pre-Conditions: A new queue must be instantiated
** Post-Conditons: N/A
******************************************************************************************/
Queue::Queue() {

		head = NULL;
		tail = NULL;

}



/******************************************************************************************
** Function: Destructor
** Description: This functions deletes all nodes and creature pointers to deallocate the 
**		dynamic memory created.
** Parameters: N/A
** Pre-Conditions: Called when the queue is destroyed
** Post-Conditons: N/A
******************************************************************************************/
Queue::~Queue() {

	if (head == NULL) {
		return;
	}

	while (head != NULL) {
		if (head == tail) {
			Node *temp = head;
			delete head->ptrToCreature;
			head = NULL;
			tail = NULL;
			delete temp;
			temp = NULL;

		}

		else {
			Node *temp = head;
			delete (head->ptrToCreature);
			head = head->prev;
			head->next = NULL;
			temp->prev = NULL;
			delete temp;
			temp = NULL;

		}
	}
}



/******************************************************************************************
** Function: Add
** Description: This function creates a new Linked Node and adds it to the Queue.
** Parameters: N/A
** Pre-Conditions: A creature pointer is passed into this function from calling function.
** Post-Conditons: The queue contains an additional node.
******************************************************************************************/
void Queue::add(Creature* c1) {

	if (head == NULL && tail == NULL) {
		Node *ptr = new Node(c1);
		tail = ptr;
		head = ptr;
		ptr = NULL;

	}

	else {
		Node * ptr = new Node(c1, tail, NULL);
		tail->prev = ptr;
		tail = ptr;
		ptr = NULL;
	}

}



/******************************************************************************************
** Function: Remove
** Description: This function deletes the first Node added in the add function.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: The queue contains one less node and the function returns the Creature 
**		pointer in the deleted node. 
******************************************************************************************/
Creature* Queue::remove() {

	if (head == NULL) {
		cout << "Nothing to remove!" << endl;
		return NULL;
	}

	else if (head == tail) {
		Node *temp = head;
		Creature* removedCreature = (head->ptrToCreature) ;
		head = NULL;
		tail = NULL;
		delete temp;
		return removedCreature;

	}

	else {
		Node *temp = head;
		Creature* removedCreature = (head->ptrToCreature);
		head = head->prev;
		head->next = NULL;
		temp->prev = NULL;							
		delete temp;
		temp = NULL;
		return removedCreature;

	}

	return 0;
}



/******************************************************************************************
** Function: Display
** Description: This function displays the Creature pointers in each node of the queue
**		without deleting them, allowing the user to "peak" at the queue. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void Queue::display() {

	if (head == NULL) {
		cout << "No players are left!" << endl;
	}

	Node * nodePtr = tail;

	while (nodePtr != NULL) {
		cout << (nodePtr->ptrToCreature)->getName() << " ";
		cout << (nodePtr->ptrToCreature)->getIdentity() << " " << endl;
		nodePtr = nodePtr->next;
	}

	nodePtr = NULL;


}



/******************************************************************************************
** Function: PlayerQueue
** Description: This function validates whether the Queue is empty and returns the 
**		corresponding bool value. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
bool Queue ::isEmpty() {

	if ((head == NULL) && (tail == NULL)) {
		return true;
	}
	else {
		return false;
	}

}