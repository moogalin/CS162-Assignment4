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
	int damageTaken;
	int attackVal;
	int defenseVal;
	int lifeValue;
	int mob;
	string name;
	string identity;
	string team;

	int numDiceAttack;
	int numDiceAttackSides;
	int numDiceDefense;
	int numDiceDefenseSides;


public:
	virtual ~Creature();
	string getName();
	string getIdentity();
	int getattackVal();
	int getDefenseVal();
	virtual int attack() = 0;
	virtual void defense(int) = 0;
	bool isDead();
	int rollDice(int amt, int sides);
	int getStrength();
	int getArmor();
	int restoreDamage();
	int getDamageTaken();


public:

};




#endif

