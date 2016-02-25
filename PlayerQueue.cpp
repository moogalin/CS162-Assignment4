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
** Description: This functions deletes all nodes to deallocate the dynamic memory created.
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
			head = NULL;
			tail = NULL;
			delete temp;

		}

		else {
			Node *temp = head;
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
** Pre-Conditions: A number input by the user is passed into this function from main.
** Post-Conditons: The queue continues an additional node, compared to before.
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
** Post-Conditons: The queue contains one less node and the function returns the integer value
**		contained in the deleted node.
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
** Description: This function displays the integers in each node of the queue at the time it
**		is called.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void Queue::display() {

	if (head == NULL) {
		cout << "Nothing to display!" << endl;
	}

	Node * nodePtr = tail;

	while (nodePtr != NULL) {
		cout << (nodePtr->ptrToCreature)->getName() << " ";
		cout << (nodePtr->ptrToCreature)->getIdentity() << " " << endl;
		nodePtr = nodePtr->next;
	}

	nodePtr = NULL;


}

bool Queue ::isEmpty() {

	if ((head == NULL) && (tail == NULL)) {
		cout << "True returned in Queue" << endl;
		return true;
	}
	else {
		cout << "False returned in Queue" << endl;
		return false;
	}

}