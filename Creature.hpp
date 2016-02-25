/******************************************************************************************
** Program Filename: Assignment 3
** Author: Megan Aldridge
** Date: February 14, 2016
** Description: This program allows a user to create two Barbarian, Vampire, Blue Men, Medusa
**		or Harry Potter (Creature objects) and subsequently enter those objects into a random
**		die roll based duel where they will lose attack, lose strength, and (if applicable)
**			use special powerups!
** Input: User will select from a menu to determine which Creatures will fight. User
**		will then choose whether to continue a fight, quit the fight, start a new battle,
**		or quit entirely.
** Output: The output displays each round of the fight including each creatures armor,
**		die roll, strength (before and after defending), and the result of the battle.
**		Menu functions also display choices to allow the user to determine if they want
**		to continue the battle, start a new one, or quit.
******************************************************************************************/


#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Creature {

protected:
	int armor;
	int strength;
	int lifeValue;
	int mob;
	string name;
	string identity;

	int numDiceAttack;
	int numDiceAttackSides;
	int numDiceDefense;
	int numDiceDefenseSides;


public:
	string getName();
	string getIdentity();
	virtual int attack() = 0;
	virtual void defense(int) = 0;
	bool isDead();
	int rollDice(int amt, int sides);
	int getStrength();
	int getArmor();
	void restoreDamage();


public:

};




#endif

