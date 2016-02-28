/******************************************************************************************
** Program Filename: Lab 6
** Author: Megan Aldridge
** Date: February 14, 2016
** Description: This program allows a user to store integers in a stack-like and queue-like
**		linked list. The user can also remove the last integer added to the stack or the
**		first integer added to the queue and display the resulting stack or queue.
** Input: User will select from a menu to determine if an integer is added or removed from
**		the stack or queue, as well as input their selected integer.
** Output: There is a menu that is output to the user as well as basic cout statements
**		indicating the results.
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
		cout << "Nothing to remove" << endl;
	
	}

	else if (head->next == NULL) {
		string removedCreature = (head->ptrToCreature)->getName();
		string removedCreatureidentity = (head->ptrToCreature)->getIdentity();
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



