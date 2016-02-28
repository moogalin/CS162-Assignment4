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

#include "Barbarian.hpp"


Barbarian::Barbarian(string charName, string teamName) {
	armor = 0;
	strength = 12;
	damageTaken = 0;
	attackVal = 0;
	defenseVal = 0;
	lifeValue = 1;
	name = charName;
	identity = "The Barbarian";
	team = teamName;
	numDiceAttack = 2;
	numDiceAttackSides = 6;
	numDiceDefense = 2;
	numDiceDefenseSides = 6;
}

Barbarian::~Barbarian() {

}

int Barbarian::attack() {

	attackVal = rollDice(numDiceAttack, numDiceAttackSides);

		return attackVal;

}


void Barbarian::defense(int attack) {

	defenseVal = rollDice(numDiceDefense, numDiceDefenseSides);

	damageTaken = (attack - armor) - defenseVal;

	if (damageTaken > 0) {
		strength -= damageTaken;
	}

	if (strength <= 0) {
		cout << " " << name << " " << identity << " has died." << endl;
		lifeValue = 0;
	}

}

