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

#ifndef STACK_HPP
#define STACK_HPP
#include <cstdlib>
#include <iostream>
#include "Creature.hpp"
using std::cin;
using std::cout;
using std::endl;

class Stack {

protected:
	struct Node {
		Creature* ptrToCreature;
		Node * next;
		Node(Creature*c1, Node* next1 = NULL ) { 
			ptrToCreature = c1;
			next = next1;
		}
	};
	Node * head;

public:
	Stack();
	~Stack();
	void add(Creature*);
	void remove();
	void display();



};

#endif
