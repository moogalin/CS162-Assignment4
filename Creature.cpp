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

#include "Creature.hpp"


Creature::~Creature() {

}

/******************************************************************************************
** Function: isDead
** Description: This function returns a bool value associated with whether or not a given 
**		creature is dead. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
bool Creature::isDead() {
	if (lifeValue == 0) {
		return true;
	}

	else {
		return false;
	}
}

/******************************************************************************************
** Function: rollDice
** Description: This function creates the dice for each specific creature based on the number
**		of defense and attack dice they have and the number of sides of each. A while loop
**		within the function ensures that the dice roll returned is the sum of each separate
**		dice roll. 
** Parameters: N/A
** Pre-Conditions: This function a specific attack value.
** Post-Conditons: Strength is changed, depending on the damage
******************************************************************************************/
int Creature::rollDice(int amt, int sides) {

	int roll = 0;

	while (amt > 0) {

		int dieRoll;

		dieRoll = (rand() % sides) + 1;

		roll += dieRoll;

		amt--;
	}

	return roll;
}


/******************************************************************************************
** Function: Attack (Virtual Function)
** Description: This virtual function is implemented uniquely in each Creature derived class.
**		However, many of the Creature children have the same attack function (unless they
**		have specific special powerups). The general attack function calls the rollDice function
**		and returns that value as the specific attack.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: This function returns
******************************************************************************************/
//virtual int attack() = 0;

/******************************************************************************************
** Function: Defense (Virtual Function)
** Description: This virtual function is implemented uniquely in each Creature derived class.
**		However, many of the Creature children have the same defense function (unless they
**		have specific special powerups). The general defense function receives an attack value
**		and determines the damage based on the attack, armor, and defense dice roll. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: This function changes the Strength value (if necessary) of its Creature. 
******************************************************************************************/
//virtual void defense(int) = 0;

/******************************************************************************************
** Function: Getter Functions to Return private member variables. 
******************************************************************************************/
int Creature::getStrength() {
	return strength;
}

string Creature::getName() {
	return name;
}

string Creature::getIdentity() {
	return identity;
}

int Creature::getDamageTaken() {
	return damageTaken;
}

int Creature::getattackVal() {
	return attackVal;
}

int Creature::getDefenseVal() {
	return defenseVal;
}

int Creature::getArmor() {
	return armor;
}

int Creature::restoreDamage() {
	int roll = rollDice(1, 6);

	if (roll == 1) {
		strength = strength + 1;
	}

	if (roll == 2) {
		strength = strength + 2;
	}

	if (roll == 3) {
		strength = strength + 3;
	}

	if (roll == 4) {
		strength = strength + 4;
	}

	if (roll == 5) {
		strength = strength + 5;
	}

	else if (roll == 6) {
		strength = strength + 6;
	}

	return roll;
}


