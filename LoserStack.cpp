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

#include "LoserStack.hpp"

/******************************************************************************************
** Function: Constructor
** Description: This functions sets the head pointer to NULL when a new stack is instantiated.
** Parameters: N/A
** Pre-Conditions: A new stack must be instantiated
** Post-Conditons: N/A
******************************************************************************************/
Stack::Stack() {

	head = NULL;

}


/******************************************************************************************
** Function: Destructor
** Description: This functions deletes all nodes to deallocate the dynamic memory created.
** Parameters: N/A
** Pre-Conditions: Called when the Stack is destroyed 
** Post-Conditons: N/A
******************************************************************************************/
Stack::~Stack() {
	if (head != NULL) {
		

		while (head->next != NULL) {
			Node *newPtr = head;
			delete (head->ptrToCreature);
			head = head->next;
			newPtr->next = NULL;
			delete newPtr;
			newPtr = NULL;
		}
			delete (head->ptrToCreature);
			delete head;
			head = NULL;
		

	}
}


/******************************************************************************************
** Function: Add
** Description: This function creates a new Linked Node and adds it to the stack. 
** Parameters: N/A
** Pre-Conditions: A number input by the user is passed into this function from main.
** Post-Conditons: The Stack continues an additional node, compared to before. 
******************************************************************************************/
void Stack::add(Creature* c1) {

	if (head == NULL) {
		Node *temp = new Node(c1);
		head = temp;
		temp = NULL;

	}

	else {
		Node *temp = new Node(c1, head);
		head = temp;
		temp = NULL;
	}

}


/******************************************************************************************
** Function: Remove
** Description: This function deletes the last Node added in the add function.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: The stack contains one less node and the function returns the integer value
**		contained in the deleted node. 
******************************************************************************************/
void Stack::remove() {

	if (head == NULL) {
		cout << "Not applicable!" << endl;
	
	}

	else if (head->next == NULL) {
		string removedCreature = (head->ptrToCreature)->getName();
		cout << removedCreature << " ";
		string removedCreatureIdentity = (head->ptrToCreature)->getIdentity();
		cout << removedCreatureIdentity << " " << endl;
		delete (head->ptrToCreature);
		delete head;
		head = NULL;

	}

	else {
		Node *remove = head;						
		string removedCreature = (head->ptrToCreature)->getName();
		cout << removedCreature	<< " ";
		string removedCreatureIdentity = (head->ptrToCreature)->getIdentity();
		cout << removedCreatureIdentity << " " << endl;
		delete (head->ptrToCreature);
		head = head->next;
		remove->next = NULL;
		delete remove;															
		remove = NULL;

	}
}


/******************************************************************************************
** Function: Display
** Description: This function displays the integers in each node of the Stack at the time it 
**		is called. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void Stack::display() {

	if (head == NULL) {
		cout << "Nothing to display!" << endl;
	}

	Node * nodePtr = head;

	while (nodePtr != NULL) {
		cout << (nodePtr->ptrToCreature)->getName() << " ";
		cout << (nodePtr->ptrToCreature)->getIdentity() << " " << endl;
		nodePtr = nodePtr->next;
	}

	delete (nodePtr);
	nodePtr = NULL;
}



