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

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdlib>
#include <iostream>
#include "Creature.hpp"
using std::cin;
using std::cout;
using std::endl;

class Queue {

protected:
	struct Node {
		Creature* ptrToCreature;
		Node * next;
		Node * prev;
		Node(Creature* creature1, Node * next1 = NULL, Node * prev1 = NULL) {
			ptrToCreature = creature1;
			next = next1;
			prev = prev1;

		}
	};
	Node * head;
	Node * tail;

public:
	bool isEmpty();
	Queue();
	~Queue();
	void add(Creature*);
	Creature* remove();
	void display();
};


#endif
